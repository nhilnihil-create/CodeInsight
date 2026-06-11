#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n,a,b,c,d,e;
  cin >> n >> a >> b >> c >> d >> e;
  ll w = min({a,b,c,d,e});
  if(n <= w){
    cout << 5 << endl;
    return 0;
  }
  ll ans = n/w - (n%w == 0);
 
  ans += 5;
  cout << ans << endl;
}
