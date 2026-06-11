#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N, X;
  cin >> N >> X;
  int a[N];
  int sum = 0;
  int ans;
  FOR(i,0,N) {
    cin >> a[i];
    sum += a[i];
  }
  int nokori = X - sum;
  ans = N;
  sort(a,a+N);
  while(nokori >= 0) {
    nokori -= a[0];
    if (nokori >= 0) ans++;
  }
  cout << ans << endl;
  return 0;
}