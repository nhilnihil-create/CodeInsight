#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  n--;
  int a[n], b[n], c[n + 1];
  c[0] = 0;
  int suma = 0, sumb = 0;
  int x, y;
  cin >> x;
  c[0] = 0;
  rep(i, n) {
    cin >> a[i];
    suma += a[i];
  }
  rep(i, n) {
    cin >> b[i];
    sumb += b[i];
    c[i + 1] = c[i] + b[i];
  }
  cin >> y;
  int ans = 0;
  rep(i, n + 1) {
    if(i != 0) suma -= a[n - i];
    ans = max(ans, suma + c[n] - c[n - i]);
  }
  cout << ans + x + y << endl;
    

  return 0;
}
