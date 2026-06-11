#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

int main() {
  int N; cin >> N;
  vector<string> v(N);
  rep(i, N) cin >> v[i];
  int n_xa = 0, n_ba = 0, n_bx = 0;
  int n_inside = 0;
  rep(i, N) {
    n_xa += v[i][0] != 'B' && v[i].back() == 'A';
    n_ba += v[i][0] == 'B' && v[i].back() == 'A';
    n_bx += v[i][0] == 'B' && v[i].back() != 'A';
    rep(k, (int)v[i].size() - 1) {
      n_inside += v[i][k] == 'A' && v[i][k + 1] == 'B';
    }
  }
  int ans = n_inside;
  ans += n_ba ? !!n_xa + (n_ba - 1) + !!n_bx : 0;
  ans += min(n_xa - (n_ba && n_xa), n_bx - (n_ba && n_bx));
  cout << ans << endl;
}
