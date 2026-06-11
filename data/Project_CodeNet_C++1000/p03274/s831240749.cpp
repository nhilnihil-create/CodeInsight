#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> vn,vp;
  rep(i,N) {
    ll x;
    cin>>x;
    if(x<0LL) vn.push_back(x);
    if(x>=0LL) vp.push_back(x);
  }
  reverse(vn.begin(),vn.end());
  ll d = INF;
  for(ll i =0LL ; i <= K; i ++) {
    if(K-i>(ll)vp.size()) continue;
    if(i>(ll)vn.size())continue;
    ll dd;
    if(i==0LL){
      dd=vp[K-1LL];
    }
    else if(i == K){
      dd=-vn[K-1LL];
    }
    else{
      dd=2LL*(-vn[i-1LL])+vp[K-i-1LL];
    }
    chmin(d,dd);
  }
  for(ll i =0LL ; i <= K; i ++) {
    if(K-i>(ll)vn.size()) continue;
    if(i>(ll)vp.size())continue;
    ll dd;
    if(i==0LL){
      dd=-vn[K-1LL];
    }
    else if(i == K){
      dd=vp[K-1LL];
    }
    else{
      dd=2LL*(vp[i-1LL])-vn[K-i-1LL];
    }
    chmin(d,dd);
  }
  cout<<d<<endl;
}