#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
   ll x, y;
  cin >> x >> y;
 
  ll ans = 0;
  for (ll i = x; i <= y; i *= 2) ans++;
  cout << ans << endl;
 
  return 0;
    
}