#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 3e5 + 5, mod = 998244353;

ll n, a, b, k, sol;
ll fakt[MAXN], inv[MAXN], povrh[MAXN], pref[MAXN];

ll add(int x, int y){
  x += y;
  if(x >= mod) return x - mod;
  return x;
}

ll mul(ll x, ll y){
  return x * y % mod;
}

ll sub(ll x, ll y){
  x -= y;
  if(x < 0) x += mod;
  return x;
}

ll pot(ll b, ll p){
    if (p % 2)
        return pot(b, p - 1) * b % mod;
    else{
        ll tmp = p ? pot(b, p / 2) % mod : 1;
        return tmp * tmp % mod;
    }
}

int main(){

  cin >> n >> a >> b >> k;
  fakt[1] = 1;
  FOR(i, 2, n + 1)
    fakt[i] = mul(fakt[i - 1], i);
  FOR(i, 1, n + 1)
    inv[i] = pot(fakt[i], mod - 2);
  FOR(i, 1, n + 1)
    povrh[i] = mul(fakt[n], mul(inv[i], inv[n - i]));
  povrh[0] = 1;
  povrh[n] = 1;

  REP(i, n + 1){
    ll x = i * a;
    ll tmp = k - x;
    if(tmp % b || x > k) continue;
    ll y = tmp / b;
    if(y > n) continue;
    sol = add( sol, mul(povrh[i], povrh[y]) );
  }
  cout << sol;
}
