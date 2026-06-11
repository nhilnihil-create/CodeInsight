#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,M;
  cin>>N>>M;
  vector<ll> X(M);
  rep(i,M) cin>>X[i];
  priority_queue<ll,vector<ll>,greater<ll>> q;
  sort(X.begin(),X.end());
  rep(i,M-1) q.push(X[i+1]-X[i]);
  ll ans = 0;
  rep(i,M-N){
    ans += q.top();
    q.pop();
  }
  cout<<ans<<endl;
}