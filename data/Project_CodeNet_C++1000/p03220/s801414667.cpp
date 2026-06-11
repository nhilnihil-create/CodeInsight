#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  //aとt-h[i]*0.006が近いもの。添え字のずれ注意
  //h[i]=(t-a)/0.006
  double ondosa = 10000.0;
  int kouho;
  for (int i = 0; i < n; i++) {
    double sa = abs(a - (t - 0.006 * h[i]));
    if (sa < ondosa) {
      ondosa = sa;
      kouho = i + 1;
    }
  }
  cout << kouho;
}