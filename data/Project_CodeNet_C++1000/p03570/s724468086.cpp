#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  string s; cin >> s;
  int len = s.length();
  map<int, int> num; num[0] = 1;
  int now = 0;
  rep(i,len) {
    now ^= (1<<(s[i]-'a'));
    if (!num[now]) num[now] = INF;
    rep(j,26) {
      if (num[now^(1<<j)]) {
        num[now] = min(num[now], num[now^(1<<j)]+1);
      }
    }
    // cout << now << ":" << num[now] << endl;
  }
  int result = now ? num[now]-1 : num[now];
  cout << result << endl;
  return 0;
}