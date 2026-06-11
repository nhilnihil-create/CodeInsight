#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  long long sum = 0;
  int mi = INT_MAX;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    sum += b;
    if (b < a) mi = min(mi, b);
  }
  if (mi != INT_MAX) cout << sum - mi << endl;
  else cout << 0 << endl;
}
