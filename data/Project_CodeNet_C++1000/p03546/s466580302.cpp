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
// #define INF 1LL<<60

const int INF = 1e9;

int main() {
    int H, W;
    cin >> H >> W;
    vector< vector<int> > c(10, vector<int>(10, INF));
    REP(i, 10) REP(j, 10) cin >> c[i][j];

    vector< vector<int> > A(H, vector<int>(W));
    REP(i, H) REP(j, W) cin >> A[i][j];

    REP(k, 10)
        REP(i, 10)
            REP(j, 10)
                if(c[i][j] > c[i][k] + c[k][j])
                    c[i][j] = c[i][k] + c[k][j];

    int ans = 0;
    REP(i, H)
        REP(j, W)
            if(A[i][j] == -1) {
                ans = ans;
            } else {
                ans += c[A[i][j]][1];
            }
    cout << ans << endl;
    return 0;
}