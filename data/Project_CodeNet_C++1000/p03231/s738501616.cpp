#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll x,ll y){
  if(y==0) return x;
  return gcd(y,x%y);
}

int main(){
  ll n,m; cin>>n>>m;
  string s,t; cin>>s>>t;
  ll j=0;
  for(int i=0;i<n;i++){
    while(i*m>n*j && j<m){
      j++;
    }
    if(m*i==n*j){
      if(s[i]!=t[j]){
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  cout<<n*m/gcd(n,m)<<endl;
}