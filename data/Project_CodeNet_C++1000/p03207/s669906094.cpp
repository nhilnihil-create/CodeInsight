#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  int maxv = 0;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    maxv = max(maxv, p[i]);
    sum += p[i];
  }
  cout << sum - maxv + (maxv / 2) << endl;
  return 0;
}