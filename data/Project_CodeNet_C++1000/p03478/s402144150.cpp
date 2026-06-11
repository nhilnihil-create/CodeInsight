#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int d_sum(int n) {
  int s = 0;

  while (n) {
    s += n % 10;
    n /= 10;
  }

  return s;
}
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, a, b;
  cin >> n >> a >> b;

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int s = d_sum(i);
    if (s >= a && s <= b) res += i;
  }
  cout << res << "\n";
}
