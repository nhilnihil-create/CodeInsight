#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int a, b, x;
  cin >> a >> b >> x;
  if (a > x || a + b < x) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}