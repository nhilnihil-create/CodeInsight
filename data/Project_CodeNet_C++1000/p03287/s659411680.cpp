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
 
int main() {
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
 
    // dp[l][r]: (l, r)内の組の総数
    map<ll, ll> mod_map;
    vector<ll> mod(N+1);
    mod_map[0] = 1;
    FOR(i, 1, N) {
        mod[i] = (mod[i-1] + A[i-1]) % M;
        if(mod_map.find(mod[i]) == mod_map.end()) {
            mod_map[mod[i]] = 1;
        } else {
            mod_map[mod[i]] += 1;
        }
    }

    // cerr << "mod_map.size = " << mod_map.size() << endl;
    // for(auto itr = mod_map.begin(); itr != mod_map.end(); ++itr) {
    //     cerr << itr->first << " : " << itr->second << endl;
    // }

    ll ans = 0;
    for(auto itr = mod_map.begin(); itr != mod_map.end(); ++itr) {
        ans += itr->second * (itr->second - 1);
    }

    cout << ans/2 << endl;
    return 0;
}