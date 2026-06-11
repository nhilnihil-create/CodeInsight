#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll f(ll a,ll b){
  ll n;
  while(a%b!=0){
    n=a%b;
    a=b;
    b=n;
  }
  return b;
}

int main(){
  int i,j,cnt=0;
  ll n,m;
  string s,t;
  cin>>n>>m;
  cin>>s>>t;
  ll d=f(n,m);
  for(i=0;i<d;i++){
    if(s[n*i/d]!=t[m*i/d]){
      cout<<-1;
      return 0;
    }
  }
  cout<<n*m/d;
}