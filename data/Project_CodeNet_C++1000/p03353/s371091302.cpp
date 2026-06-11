#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll INF = 1101101101101;
typedef pair<int, int> P;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.length();
  int cnt = 0;
  vector<string> c;
  rep(i, 26) {
    map<string, bool> ma;
    rep(j, n) {
      if ((char)(i + 'a') == s[j]) {
        for (int k = 1; k <= 5; k++) {
          if (j + k > n) break;
          if (ma[s.substr(j, k)] == false) {
            c.push_back(s.substr(j, k));
            ma[s.substr(j, k)] = true;
            cnt++;
          }
        }
      }
    }
    if (cnt >= k) {
      break;
    }
  }
  sort(c.begin(), c.end());
  cout << c[k - 1] << endl;
}
