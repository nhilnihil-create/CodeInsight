#include <bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair <int, int>
#define iiii pair <int, pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i, x) for(int (i) = 0; (i) < (x); (i)++)
inline int getint() {
  int x = 0, p = 1; char c = getchar();	
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
//ruogu_alter
#define int ll 
const int N = 1005;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
string hh = "DLRU";
int n, a[N], b[N];
bool flag[2];
string res;
//
signed main() {
  int q = getint();
  rep(i, q) {
    a[i] = getint(), b[i] = getint();
    flag[a[i] + b[i] & 1] = true;
  }
  if (flag[0] && flag[1]) return !printf("%d\n", -1);
  printf("%d\n", 31 + flag[0]);
  rep(i, 31) printf("%d ", (1 << i));
  if (flag[0]) printf("%d ", 1);
  printf("\n");
  rep(iii, q) {
    string res = "";
    int x = a[iii], y = b[iii];
    if (flag[0]) {
      --x; 
      res += 'R';
    }
    for (int i = 30; i >= 0; i--) {
      rep(j, 4) {
        int fx = x + dx[j] * (1 << i), fy = y + dy[j] * (1 << i);
        if (abs(fx) + abs(fy) < (1 << i)) {
          res += hh[j];
          x = fx; y = fy;
          break;
        }
      }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
  }
  return 0;
}
