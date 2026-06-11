#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100010]; 
int main() {
  int n; 
  cin >> n;
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  int ans = 0;
  int x = a[0];
  int i = 0;

  //vector<int> g;
  while (i < n)
  {
    int num = 0;
    while (a[i] == x)
    {
      num++;
      i++;
    }
    if (num == x) continue;
    else if (num < x) ans += num;
    else  ans += num-x;
    x = a[i];
  }
  cout << ans << endl;
  return 0;
}