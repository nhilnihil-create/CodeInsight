#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int n;
  cin >> n;

  int c[200100];
  rep(i, n) cin >> c[i];

  int f[200100] = {};
  ll a[200100];
  a[0] = 0; a[1] = 1; f[c[0]] = 1;
  
  for (int i = 2; i <= n; i++) {
    
    if (f[c[i - 1]] != i - 1) {
      a[i] = (a[i - 1] + a[f[c[i - 1]]]) % MOD;
    } else {
      a[i] = a[i - 1];
    }
    //cout << "f(i) = " << f[c[i - 1]] << endl;
    //cout << a[i] << endl;
    f[c[i - 1]] = i;
    
  }

  cout << a[n] << endl;

  return 0;

}
  
    
