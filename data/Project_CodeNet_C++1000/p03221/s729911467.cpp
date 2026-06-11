#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
int INF = 1e9+7;
// const long long INF = 1LL<<60;


int main(){
  int N, M;
  cin >> N >> M;
  vector<int> P(M), Y(M);
  rep(i, M){
    cin >> P[i] >> Y[i];
    --P[i];
  }
  vector<vector<int>> v(N);
  rep(i, M) v[P[i]].push_back(Y[i]);

  rep(i, N){
    sort(v[i].begin(), v[i].end());
    v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
  }

  rep(i, M){
    int pid = P[i];
    printf("%06d", pid + 1);
    int id = lower_bound(v[pid].begin(), v[pid].end(), Y[i]) - v[pid].begin() + 1;
    printf("%06d\n", id);
  }

  return 0;
}
