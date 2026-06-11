#include <cmath>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

int n;
vector<string> a;

void input() {
  cin >> n;

  a.resize(n);
  for (auto&& i : a)
    cin >> i;
}

int count(string_view where, string_view what) {
  int ans = 0;

  int pos = (int)where.find(what);

  while (pos != -1) {
    ++ans;

    pos = (int)where.find(what, pos + 1);
  }

  return ans;
}

void solve() {
  int ans = 0;

  for (auto&& i : a)
    ans += count(i, "AB");

  int cnt1 = 0;
  int cnt2 = 0;
  int cnt3 = 0;

  for (auto&& i : a) {
    if (i[0] == 'B' && i.back() == 'A') {
      ++cnt1;

      continue;
    }

    cnt2 += i[0] == 'B';
    cnt3 += i.back() == 'A';
  }

  if (cnt1 > 0) {
    if (cnt2 + cnt3 > 0) {
      ans += cnt1 + min(cnt2, cnt3);
    } else {
      ans += cnt1 - 1;
    }
  } else {
    ans += min(cnt2, cnt3);
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.precision(16);
  cout << fixed;

  int _times = 1;

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  cin >> _times;
#endif

  while (_times--) {
    input();
    solve();
  }
}
#include <cmath>

