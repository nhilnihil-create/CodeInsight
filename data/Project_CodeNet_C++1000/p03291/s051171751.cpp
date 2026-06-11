#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)
using ll=long long;
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  ll a=0;
  ll b=0;
  ll c=0;
  ll cur=1;
  rep(i,0,n){
    if(s[i]=='A'){
      a+=cur;
      a%=mod;
    }
    else if(s[i]=='B'){
      b+=a;
      b%=mod;
    }
    else if(s[i]=='C'){
      c+=b;
      c%=mod;
    }
    else{
      ll d=3*a+cur;
      ll e=3*b+a;
      ll f=3*c+b;
      d%=mod;
      e%=mod;
      f%=mod;
      a=d;
      b=e;
      c=f;
      cur*=3;
      cur%=mod;
    }
  }
  //cout<<a<<endl;
  //cout<<b<<endl;
  cout<<c<<endl;
}