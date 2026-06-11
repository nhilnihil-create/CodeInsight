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
    int Q;
    cin >> Q;

    vector<int> is_2017like(100005);
    REP(i, 100005) {
        if(i%2 == 0) continue;
        map<ll, ll> factors1 = prime_factor(i);
        map<ll, ll> factors2 = prime_factor((i+1)/2);

        if(factors1[i] == 1 && factors2[(i+1)/2] == 1)
            is_2017like[i] = 1;
    }

    vector<int> acum(100005);
    FOR(i, 1, 100005) {
        acum[i] = acum[i-1] + is_2017like[i];
    }

    REP(i, Q) {
        int l, r;
        cin >> l >> r;
        cout << acum[r] - acum[l-1] << endl;
    }

    return 0;
}