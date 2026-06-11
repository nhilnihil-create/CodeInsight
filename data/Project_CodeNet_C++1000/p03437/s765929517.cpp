#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  ll x, y;
  cin >> x >> y;
  if (x % y == 0) cout << -1 << endl;
  else cout << x << endl;
  return 0;
}