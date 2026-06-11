#include <bits/stdc++.h>
// until dimension reduction.

using namespace std;
typedef long long LL;

#define LOG(...) fprintf (stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

const int INF = 0x3f3f3f3f, N = 1005, M = 45;
const LL INFL = 0x3f3f3f3f3f3f3f3fll;

int n, x[N], y[N];
char s[N][M];  
int main() {
  scanf("%d", &n);

  int cc = 0; 
  for (int i = 1; i <= n; i++)
    scanf ("%d%d", &x[i], &y[i]), cc += (abs(x[i]) + abs(y[i])) % 2; 
  
  if (cc != 0 && cc != n) return puts("-1"), 0; 
  
  int m = 31 + (cc == 0); cout << m << endl; 
  for (int i = 0; i <= 30; i++) cout << (1 << i) << " ";
  if (m == 32) cout << "1";
  cout << endl; 

  for (int i = 1; i <= n; i++) {
    if (cc == 0) s[i][31] = 'R', x[i]--; 

    for (int d = 30; d >= 0; d--) {
      if (abs(x[i]) > abs(y[i])) {
        if (x[i] < 0) s[i][d] = 'L', x[i] += (1 << d); 
        else s[i][d] = 'R', x[i] -= (1 << d); 
      } else {
        if (y[i] < 0) s[i][d] = 'D', y[i] += (1 << d);
        else s[i][d] = 'U', y[i] -= (1 << d); 
      }
    }

    puts(s[i]); 
  }
  return 0;
}
