#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
    ll N;
    cin >> N;

    // vector<ll> dp(100);
    // dp[0] = 1;
    map<ll, ll> factors;
    factors[1] = 1;
    FOR(i, 2, N) {
        map<ll, ll> i_factor = prime_factor(i);
        for(auto p = i_factor.begin(); p != i_factor.end(); ++p) {
            factors[p->first] += p->second;
        }
    }


    vector<ll> f3 = vector<ll>(101), f5 = vector<ll>(101), f15 = vector<ll>(101), f25 = vector<ll>(101), f75 = vector<ll>(101);

    for(auto p = factors.begin(); p != factors.end(); ++p) {
        // cerr << "a_i = " << p->first << " n_i = " << p->second << endl;
        if(p->second >= 74) f75[p->first]++;
        if(p->second >= 24) f25[p->first]++;
        if(p->second >= 14) f15[p->first]++;
        if(p->second >= 4) f5[p->first]++;
        if(p->second >= 2) f3[p->first]++;
    }

    // REP(i, 101) {
    //     cerr << f3[i] << " " << f5[i] << " " << f25[i] << endl;
    // }

    ll ans = 0;
    FOR(i, 1, 100) if(f75[i] > 0) ans++;
    FOR(i, 1, 100) FOR(j, 1, 100) if(i != j && f5[i] > 0 && f15[j] > 0) ans++; 
    FOR(i, 1, 100) FOR(j, 1, 100) if(i != j && f3[i] > 0 && f25[j] > 0) ans++; 
    FOR(i, 1, 100) FOR(j, 1, 100) FOR(k, 1, j-1) if(i != j && j != k && k != i && f3[i] > 0 && f5[j] > 0 && f5[k] > 0) ans++; 

    cout << ans << endl;

    return 0;
}