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

struct block {
    int w, s;
    ll v;
};

bool operator<(const block& x, const block& y)
{
    return x.w + x.s < y.w + y.s;
}

int main() {
    int N;
    cin >> N;
    // vector<int> w(N), s(N);
    // vector<ll> v(N);
    vector<block> blocks(N);
    for(int i=0; i<N; i++){
        int x, y;
        ll z;
        cin >> x >> y >> z;
        blocks[i] = block{x, y, z};
    }

    sort(blocks.begin(), blocks.end());

    vector<vector<ll>> dp(N, vector<ll>(2e4+10, -1));

    dp[0][0] = 0;
    dp[0][blocks[0].w] = blocks[0].v;
    for(int i=1; i<N; i++) {
        block b = blocks[i];
        // cerr << "b.w = " << b.w << " b.s = " << b.s << " b.v = " << b.v << endl;
        for(int w=0; w<=2e4+10; w++) {
            if(b.s >= w - b.w && w - b.w >=0 && dp[i-1][w-b.w] >= 0) {
                // cerr << "    " << "w = " << w << " s = " << b.s  << " w-b.w = " << w-b.w << " dp[i-1][w-b.w] = " << dp[i-1][w-b.w];
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-b.w] + b.v);
                // cerr << " dp[i][w] = " << dp[i][w] << endl;
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    ll ans = 0;
    for(int w=0; w<=2e4+10; w++)
        if(ans < dp[N-1][w]) ans = dp[N-1][w];

    cout << ans << endl;
    return 0;
}