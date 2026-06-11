#include <iostream>
#include <iomanip>

using namespace std;

double ETA = 1e-12;

int main() {
  int n, k;
  cin >> n >> k;

  double div1 = k;
  double div2 = div1 / 2;
  double prob = 0.5;
  double vsum = 0;

  while (1 <= div1 + ETA) {
    if (div2 <= n && div1 <= n)
      vsum += int(int(div1 + ETA) + 1 - div2 + ETA) * prob;
    else if (div2 <= n)
      vsum += int(n + 1 - div2 + ETA) * prob;

    if (div1 <= n && div1 - int(div1) <= ETA && -ETA<=div1 - int(div1))
      vsum -= prob;

    div1 = div2;
    div2 /= 2;
    prob /= 2;
  }

  double vsum2 = (double(n) - k + 1) / n;
  if (vsum2 < 0)
    cout << fixed << setprecision(15) << vsum / n << endl;
  else
    cout << fixed << setprecision(15) << vsum / n + vsum2 << endl;
}