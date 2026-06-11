#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(nullptr);
  int n;
  cin >> n;
  int v[n], c[n];
  for (int i = 0; i < n;++i)
    cin >> v[i];
  for (int i = 0; i < n;++i)
    cin >> c[i];
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int diff = v[i] - c[i];
    if(diff>0)
      sum += diff;
  }
  cout << sum;
  return 0;
}