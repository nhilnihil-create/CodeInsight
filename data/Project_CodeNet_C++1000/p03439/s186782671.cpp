#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<62;
constexpr double eps = (1e-9);

int strtoi(string& s) {
  if (s == "Vacant") return 0;
  if (s == "Male") return 1;
  return 2;
}

// l~u の範囲を探す
void solve(vector<int>& seats, const int& l, const int& u) {
  int mid = l + (u - l) / 2;
  cout << mid << endl;
  string s;
  cin >> s;
  seats[mid] = strtoi(s);
  if (seats[mid] == 0) return;
  if ((mid - l) % 2 == 0 && seats[l] != seats[mid]) solve(seats, l, mid);
  else solve(seats, mid, u);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> seats(n, -1);

  cout << 0 << endl;
  string s;
  cin >> s;
  seats[0] = strtoi(s);
  if (seats[0] == 0) return 0;
  cout << n - 1 << endl;
  cin >> s;
  seats[n-1] = strtoi(s);
  if (seats[n-1] == 0) return 0;

  int l = 0;
  int u = n-1;

  rep(i, 18) {
    int mid = l + (u - l) / 2;
    cout << mid << endl;
    string s;
    cin >> s;
    seats[mid] = strtoi(s);
    if (seats[mid] == 0) return 0;
    if ((mid % 2 == l % 2 && seats[mid] != seats[l]) || (mid % 2 != l % 2 && seats[mid] == seats[l])) {
      u = mid;
    } else {
      l = mid;
    }
  }

  return 0;
}
