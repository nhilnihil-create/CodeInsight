#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b) cout << c << endl;
  else if (a == c) cout << b << endl;
  else cout << a << endl;
  return 0;
}