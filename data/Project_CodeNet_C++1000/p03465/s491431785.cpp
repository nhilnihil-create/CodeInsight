#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  cin >> n;
  vector<int> a(n);
  range(i, 0, n) cin >> a[i];
  const int N = 4000010;
  bitset<N> st;
  st[0] = 1;
  range(i, 0, n) {
    st |= st << a[i];
  }
  int sum = 0;
  range(i, 0, n) sum += a[i];
  range(i, (sum + 1) / 2, sum + 1) {
    if(st[i]) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
