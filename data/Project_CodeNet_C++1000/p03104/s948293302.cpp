#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

ll f(ll x) {
  ll loop = 2;
  ll res = 0;
  rep(i, 50) {
    ll cnt = (x / loop) * (loop / 2);
    ll remain = x % loop;
    cnt += max(0LL, remain - loop / 2 + 1);
    if(cnt % 2) res += pow(2, i);
    loop *= 2;
  }
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  --a;
  ll fa = f(a);
  // cout << fa << endl;
  ll fb = f(b);
  // cout << fb << endl;
  ll ans = fb^fa;

  cout << ans << endl;
}