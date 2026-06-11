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
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
  string s;
  cin >> s;
  vector<int> cnt(3);
  for(int i = 0; i < s.size(); i++) {
    cnt[s[i] - 'a']++;
  }
  int mi = *min_element(all(cnt));
  int ma = *max_element(all(cnt));
  if (ma - mi > 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(16);
  solve();
  return 0;
}