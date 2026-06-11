#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

ll mod = 1000000007;


// 文字列 s に含まれる 'AB' の数を数える
int count_ab(const string& s) {
  int count = 0;
  string find_word("AB");
  auto pos = s.find(find_word);
  while (pos != string::npos) {
    count++;
    pos = s.find(find_word, pos + find_word.size());
  }
  return count;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> black(n, 0);
  vector<int> white(n, 0);

  int ans = INF;
  int n_black = 0;
  int n_white = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      n_white++;
      if (i == 0) black[i] = 0;
      else black[i] = black[i-1];
    }
    if (s[i] == '#') {
      n_black++;
      if (i == 0) black[i] = 1;
      else black[i] = black[i-1] + 1;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '.') {
      if (i == n - 1) white[i] = 1;
      else white[i] = white[i+1] + 1;
    }
    if (s[i] == '#') {
      if (i == n - 1) white[i] = 0;
      else white[i] = white[i+1];
    }
  }

  chmin(ans, n_white);
  chmin(ans, n_black);

  for (int i = 0; i < n - 1; i++) {
    chmin(ans, black[i] + white[i+1]);
  }

  cout << ans << endl;

  return 0;
}
