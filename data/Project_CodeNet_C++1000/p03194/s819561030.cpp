#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,p;
  cin>>n>>p;
  ll ans = 1;
  ll t = p;
  map<ll, ll> m = prime_factor(p);
  for(auto x:m) {
    ans *= (ll)pow(x.first, x.second / n);
  }
  cout << ans << endl;

  return 0;
}
