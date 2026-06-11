#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#define all(x) (x).begin(), (x).end()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end());

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int dx = x2 - x1;
  int dy = y2 - y1;

  printf("%d %d %d %d\n", x2 - dy, y2 + dx, x1 - dy, y1 + dx);
}