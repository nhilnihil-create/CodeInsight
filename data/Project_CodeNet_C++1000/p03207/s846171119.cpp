#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long inf = numeric_limits<long long>::max();
int main()
{
  int n, m, t, total;
  m = 0;
  t = 0;
  total = 0;
  cin >> n;
  rep(i, n) {
    t = 0;
    cin >> t;
    if (t > m) {
      m = t;
    }
    total += t;
  }
  cout << total - (m / 2) << endl;
  return 0;
}