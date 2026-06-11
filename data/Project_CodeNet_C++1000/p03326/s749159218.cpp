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

ll sign(ll A){
    if(A>=0) return 1;
    else return 0;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    REP(i, N) cin >> x[i] >> y[i] >> z[i];

    ll ans = 0;
    for(int s=0; s<(1<<3); s++) {
        bitset<3> b = bitset<3>(s);
        vector<ll> candidates(N);
        REP(i, N) {
            candidates[i] = ll(2*b[0]-1) * x[i] + ll(2*b[1]-1) * y[i] + ll(2*b[2]-1) * z[i];
        }
        sort(ALL(candidates));
        ll cand = 0;
        REP(j, M) cand += candidates[N-1-j];
        if(ans < cand) ans = cand;
    }

    cout << ans << endl;
    
    return 0;
}