  #include <iostream>
  #include <vector>
  #include <string.h>
  #include <stack>
  #include <queue>
  #include <algorithm>
  #include <climits>
  #include <cmath>
  #include <map>
  #include <set>
  #include <assert.h>
  #include <stdio.h>
  #define REP(i,n) for(ll i=0;i<(n);i++)
  #define MOD 1000000007
  #define int long long
  #ifdef int
  const long long INF = LLONG_MAX / 10;
  #else
  const int INF = 1010101010;
  #endif
  using namespace std;
  typedef long long ll;
  typedef vector<vector<ll> > mat;
  typedef pair<int, int> P;
  //typedef pair<double, double> P;
  const int dx[9] = {-1, 0, 0, 1, -1, -1, 1, 1, 0};
  const int dy[9] = {0, -1, 1, 0, -1, 1, -1, 1, 0};
  
  string s;
  int x, y;
  const int Z = 18003;
  const int N = 2 * Z + 1;
  bool dp[2][2][N];
  //char hoge[505050];
  // char s[N];

  signed main() {
    cin >> s;
    // scanf("%s", s);
    cin >> x >> y;
    // scanf("%lld%lld", &x, &y);
    int n = s.length();
    // int n = strlen(s);

    // REP(i,8000) s += 'a';

    dp[0][0][Z] = dp[1][0][Z] = 1;

    int pos = 0LL;
    while (pos < n && s[pos] == 'F') {
      pos++;
      x--;
    }

    int t = 0LL;
    while (pos < n) {
      pos++;
      t ^= 1;
      int L = 0;
      while (pos < n && s[pos] == 'F') {
        pos++;
        L++;
      }
      REP(i,N) dp[t][1][i] = 0; //1の方は計算結果
      REP(i,N) {
        if (!dp[t][0][i]) continue;
        dp[t][1][i-L] = dp[t][1][i+L] = 1;
      }
      REP(i,N) dp[t][0][i] = dp[t][1][i];
    }

    if (dp[0][0][Z+x] && dp[1][0][Z+y]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

    return 0;
  }