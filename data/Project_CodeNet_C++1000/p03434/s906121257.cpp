#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[101];
  for (int i=0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>()); //a[0:N]を大きい順にソート
  int sum_a = 0;
  int sum_b = 0;
  for (int i=0; i < n; i++) {
      if(i%2==0) sum_a += a[i];
      else sum_b += a[i];
  }
  cout << sum_a-sum_b << endl;
}