#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<vector<ll>> v(N,vector<ll>(2));
  for(ll i = 0; i < N; i++) cin>>v[i][0]>>v[i][1];
  vector<vector<ll>> w(N,vector<ll>(2));
  for(ll i = 0; i < N; i++) {
    w[i][0]=v[i][0]+v[i][1];
    w[i][1]=i;
  }
  sort(w.begin(),w.end());
  reverse(w.begin(),w.end());
  ll T=0LL,S=0LL;
  for(ll i = 0; i < N; i++){
    if(i%2==0) T+=v[w[i][1]][0];
    if(i%2==1) S+=v[w[i][1]][1];
  }
  cout<<T-S<<endl;
}