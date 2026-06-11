#include <iostream>
using namespace std;
long n, a[100010];
int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];

  long L = 2, R = 2;
  for(int i = n-1; i >= 0; --i) {
    L = (L + a[i] - 1) / a[i] * a[i];
    R = R / a[i] * a[i] + a[i] - 1;
  }
  if(L >= R) cout << -1;
  else cout << L << " " << R;
  return 0;
}