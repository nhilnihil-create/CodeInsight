#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;


int main(){
  ll k,a,b;
  cin >> k >> a >> b;
  ll ans = k+1;
  if(a+2 < b) {
    ll trade = max(ll(0),(k-(a-1))/2);
    ll res = 1 + k - 2*trade;
    ans = trade*(b-a)+res;
  }
  cout << ans << endl;
}
