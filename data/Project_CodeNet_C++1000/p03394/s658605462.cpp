#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 2e4, M = 3e4;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  if (n == 3) {
    cout << "2 5 63\n";
    return 0;
  }
  if (n == 4) {
    cout << "2 5 20 63\n";
    return 0;
  }

  VI ans {2, 4, 3, 9, 6};
  n -= 5;

  int i2 = 8;
  while (n >= 2) {
    if (i2 + 2 <= M) {
      ans.push_back(i2);
      ans.push_back(i2 + 2);
      i2 += 6;
      n -= 2;
    } else {
      break;
    }
  }

  int i3 = 9+6;
  while (n >= 2) {
    if (i3 + 6 <= M) {
      ans.push_back(i3);
      ans.push_back(i3 + 6);
      n -= 2;
      i3 += 12;
    } else {
      break;
    }
  }

  int i6 = 6+6;
  while (n >= 1) {
    n--;
    ans.push_back(i6);
    i6 += 6;
  }

  for (int x: ans) cout << x << ' ';
  cout << endl;

  return 0;
}
