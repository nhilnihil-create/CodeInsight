// review
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const int MAXN = 110;
const double INF = 300;

int n;
double t[MAXN], v[MAXN];

double calc(double x) {
  double retV = INF;
  double currentT = 0;
  for (int i=0;i<=n+1;i++) {
    if (x <= currentT) {
      retV = min(retV, v[i] + currentT - x);
    } else if (currentT <= x && x <= currentT + t[i]) {
      retV = min(retV, v[i]);
    } else {
      retV = min(retV, v[i] + x - currentT - t[i]);
    }
    currentT += t[i];
  }
  if (x >= currentT) {
    retV = 0;
  }
  return retV;
}

void solve() {
  double currentT = 0;
  double currentV = 0;
  double sum = 0;
  for (int i=1;i<=n;i++) {
    for (double x = 0;x<t[i];x+=0.5) {
      double nextV = calc(x + currentT + 0.5);
      sum += 0.25 * (currentV + nextV);
      currentV = nextV;
    }
    currentT += t[i];
  }
  cout << setprecision(10) << sum << endl;
}

int main() {
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> t[i];
  }
  for (int i=1;i<=n;i++) {
    cin >> v[i];
  }
  solve();
}
