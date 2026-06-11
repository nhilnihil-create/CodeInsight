#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int main() {
  int n;
  string s;

  cin >> n >> s;

  int west_reverse_count = 0;
  int east_reverse_count = 0;
  rep(i, s.size()) {
    if(s[i] != 'W') {
      east_reverse_count++;
    }
  }

  int min_reverse_count = n;
  rep(i, s.size()) {
    if(s[i] != 'W') {
      east_reverse_count--;
    }
    min_reverse_count = min(min_reverse_count, west_reverse_count + east_reverse_count);
    if(s[i] != 'E') {
      west_reverse_count++;
    }
  }

  cout << min_reverse_count << endl;
}
