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
  int n, k;
  cin >> n >> k;
  vector<int> seq(n);
  rep(i, n) {
    cin >> seq[i];
  }
  int m = 0;
  rep(i, n) {
    if (i == 0) continue;
    if (seq[i] < seq[m]) {
      m = i;
    }
  }
  if (n <= k) {
    cout << 1 << endl;
  } else {
    cout << ceil((n-1)/((k-1)*1.0));
  }

  return 0;
}