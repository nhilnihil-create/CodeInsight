#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int d, n;
  cin >> d >> n;
  int ans = 0;
  int exp = 1;
  rep(i, d) exp *= 100;
  if(n == 100) ans = exp*n + exp;
  else ans = exp*n;
  
  cout << ans << endl;
  return 0;
}