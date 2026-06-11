#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;
  
ll gcd(ll a, ll b){
  if(a==1 || b==1)return 1;
  if (a < b)swap(a,b);
  
  return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}

int main(){
  ll l,n, m;cin>>n>>m;
  string s,t;cin>>s>>t;
  l = lcm(n,m);
  map<ll, char>log;
  rep(i,n)log[1+i*l/n]=s[i];
  bool f=true;
  rep(i,m){
    ll index = 1+i*l/m;
    if(log.count(index)>0 && log[index]!=t[i]){
      f=false;
      break;
    }
  }

  if(f)cout<<l;
  else cout<<-1;

  return 0;
}

