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
  int n;
  cin >> n;
  int ans = 0;
  rep(i, 3) {
    int p = pow(10, i);
    int v = n % 10;
    if (v == 9) {
      ans += 1*p;
    } else if (v == 1) {
      ans += 9*p;
    } else {
      ans += v * p;
    }
    n /= 10;
  }
  cout << ans << endl;
  
  return 0;
}