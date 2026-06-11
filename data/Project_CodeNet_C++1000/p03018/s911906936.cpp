#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  string s;
  cin >> s;
  ll ans = 0;
  int l = 0;  // Aが連続した回数
  REP(i, s.size() - 2) {
    if (s[i] == 'A')
      l++;
    else
      l = 0;
    if (s[i] != 'A' || s[i + 1] != 'B' || s[i + 2] != 'C') continue;
    ans += l;

    swap(s[i - l + 1], s[i + 1]);
    swap(s[i - l + 2], s[i + 2]);
        l -= 2;
  }
  cout << ans << endl;
}