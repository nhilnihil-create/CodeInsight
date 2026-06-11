#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    B[i] = a[i] - i - 1;
  }  
  sort(B.begin(), B.end());
  int b = B[n/2];
  ll ans = 0;
  for (int i = 0; i < n; i++) ans += abs(a[i] - (b+(i+1)));
  cout << ans << endl;
}