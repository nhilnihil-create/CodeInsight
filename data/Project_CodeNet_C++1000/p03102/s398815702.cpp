#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;


int main()
{
  int n, m, c;
  cin >> n >> m >> c;
  int b[m], a[n][m];
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int s = 0, x[n];
  fill(x, x + n, 0);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      x[i] += a[i][j]*b[j];
    }
    int br = 0;
  for(int i = 0; i < n; i++) {
      if(x[i] + c > 0)
        br++;
    }
  cout << br;
}
