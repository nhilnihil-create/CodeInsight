#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> v) {os << "(" << v.first << ", " << v.second << ")"; return os;}


void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(all(A));
  int ii, jj;
  for (int i = 1; i < N; i++) {
    int j = lower_bound(all(A), A[i] / 2) - A.begin();
    double mi = 1e9 + 10;
    if (i != j + 1 && j + 1 < N) {
      if (mi > fabs(A[i] / 2.0 - A[j + 1])) {
        mi = fabs(A[i] / 2.0 - A[j + 1]);
        ii = i;
        jj = j + 1;
      }
    }
    if (i != j - 1 && j - 1 >= 0) {
      if (mi > fabs(A[i] / 2.0 - A[j - 1])) {
        mi = fabs(A[i] / 2.0 - A[j - 1]);
        ii = i;
        jj = j - 1;
      }
    }
    if (i != j && mi > fabs(A[i] / 2.0 - A[j])) {
      mi = fabs(A[i] / 2.0 - A[j]);
      ii = i;
      jj = j;
    }
  }
  cout << A[ii] << " " << A[jj] << endl;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(16);
  solve();
  return 0;
}