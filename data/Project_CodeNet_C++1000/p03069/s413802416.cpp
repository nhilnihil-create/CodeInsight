#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  string S; cin >> S;

  vector<int> whsum(N+1, 0);
  vector<int> blsum(N+1, 0);
  for (int i = 0; i < N; ++i) {
    whsum[i+1] = whsum[i] + (S[i] == '.' ? 1 : 0);
    blsum[i+1] = blsum[i] + (S[i] == '#' ? 1 : 0);
  }

  long long res = 1LL<<60;
  for (int left = 0; left <= N; ++left) {
    long long tmp = 0;
    // left を全部白に
    tmp += blsum[left] - blsum[0];

    // right を全部黒に
    tmp += whsum[N] - whsum[left];

    chmin(res, tmp);
  }

  cout << res << endl;
}

// goal: ...###

// 5
// #.##.
