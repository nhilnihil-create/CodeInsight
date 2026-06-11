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
  sort(seq.begin(), seq.end());
  long long ans = inf;
  rep(i, n-k+1) {
    ans = min(ans, (long long)abs(seq[i] - seq[i+k-1]));
  }
  cout << ans << endl;
  return 0;
}