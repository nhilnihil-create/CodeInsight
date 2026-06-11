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
  int d = n / 100;
  if (n / d == 111 && n % d == 0) {
    cout << n << endl;
  } else {    int c = 100*d + 10*d + d;
    if (c < n) {
      cout << c+111 << endl;
    } else {
      cout << c << endl;
    }
  }
  return 0;
}