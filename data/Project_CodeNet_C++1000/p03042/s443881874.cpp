#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  string s;
  cin >> s;
  int l = (s[0] - '0') * 10 + (s[1] - '0');
  int r = (s[2] - '0') * 10 + (s[3] - '0');
  if (l > 12 || l == 0) {
    if (r > 12 || r == 0) {
      cout << "NA" << endl;
      return 0;
    }
    cout << "YYMM" << endl;
    return 0;
  }
  if (r > 12 || r == 0) {
    cout << "MMYY" << endl;
    return 0;
  }
  cout << "AMBIGUOUS" << endl;
  return 0;
}