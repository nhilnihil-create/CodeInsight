#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> times(n);
  rep2(i, 1, n) {
    string tmp;
    tmp.push_back(s[i - 1]);
    tmp.push_back(s[i]);
    if (tmp == "AC") {
      if (i == 0)
        times[i]++;
      else
        times[i] = times[i - 1] + 1;
    }
    times[i + 1] = times[i];
  }
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << times[r] - times[l] << endl;
  }
  return 0;
}