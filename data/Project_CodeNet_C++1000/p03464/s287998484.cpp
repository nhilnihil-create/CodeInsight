/**
 *    author:  tourist
 *    created: 09.01.2018 11:59:26       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
  }
  long long low = 2, high = 2;
  for (int i = k - 1; i >= 0; i--) {
    low = (low + a[i] - 1) / a[i] * a[i];
    high = high / a[i] * a[i] + (a[i] - 1);
    if (low > high) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << low << " " << high << endl;
  return 0;
}
