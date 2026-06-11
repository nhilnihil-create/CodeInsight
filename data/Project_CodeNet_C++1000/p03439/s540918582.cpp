#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

bool betemp(string sl, string sr, int l, int r) {
  if (sl == sr)
    return (r - l) % 2 == 1;
  else
    return (r - l) % 2 == 0;
}

int main() {
  int n;
  while (cin >> n) {
    string vac = "Vacant";
    string sl, sr, str;
    int l = 0, r = n / 2;
    cout << l << endl;
    cin >> sl;
    if (sl == vac) return 0;
    cout << r << endl;
    cin >> sr;
    if (sr == vac) return 0;

    if (!betemp(sl, sr, l, r)) {
      swap(sl, sr), l = r, r = n;
    }
    while (r - l > 1) {
      int m = (l + r) / 2;
      cout << m << endl;
      cin >> str;
      if (str == vac) return 0;
      if (betemp(sl, str, l, m))
        sr = str, r = m;
      else
        sl = str, l = m;
    }
  }
}