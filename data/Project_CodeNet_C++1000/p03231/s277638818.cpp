#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

//a,bのGCD
int GCD(int a, int b){
  if(a<b){swap(a,b);}  
  if(a%b==0){return b;}
  else{return GCD(a%b,b);}
}

int main() {
  ll n,m; string s,t;
  cin>>n>>m>>s>>t;
  ll ans=0;
  ll g=GCD(n,m);
  if(s[0]!=t[0]){ans=-1;}
  else if(g==1){ans=n/g*m;}
  else{
    bool b=true;
    rep(i,g){
      if(s[n/g*i]!=t[m/g*i]){b=false;break;}
    }
    if(b){ans=n/g*m;}
    else{ans=-1;}
    
  }
  cout<<ans;
}