#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  ll n, k;
  cin >> n >> k;

  ll sum = 0;
  if (k == 0) {
    sum = n * n;
    cout << sum << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (i >= k+1) {
      sum += ((n + 1) / i) * (i - k);
      //printf("i=%d, sum=%lld\n", i, ((n + 1) / i) * (i - k));
      if ((((n + 1) % i) - k > 0)) {
        //printf("i=%d\n", i);
        sum += ((n + 1) % i) - k;
      }
    }
  }
  cout << sum << endl;
} 


