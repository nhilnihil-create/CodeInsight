#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

map<ll,ll> pfact(ll n) {
  map<ll,ll> ret;
  while(n%2==0) {ret[2]++;n/=2;}
  for(ll i=3;i*i<=n;i+=2) while(n%i==0) {ret[i]++;n/=i;}
  if(n!=1) ret[n]=1;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,ans=0;cin>>n;
  for(ll i=1;i<=n;i+=2) {
    map<ll,ll> mp=pfact(i);
    ll v=1;
    for(P p:mp) v*=(p.second+1);
    if(v==8) ans++; 
  }
  print(ans);
  return 0;
}