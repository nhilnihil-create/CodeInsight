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
  ll n;
  cin >> n;

  ll sum = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll m = i - 1;
      ll anotherm = n / i - 1;
      if ((m != 0) && ((n / m) == (n % m))) {
        sum += m; 
      }
      if ((i != n/i) && (anotherm != 0)) {
        if ((n / anotherm) == (n % anotherm)) {
          sum += anotherm;
        }
      }
    }
  }
  cout << sum << endl;
}
