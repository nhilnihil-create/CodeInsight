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
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A+2), t(B+2), X(Q), s_rev(A+2), t_rev(B+2);
    s[A] = 1e12;
    t[B] = 1e12;
    s[A+1] = -1e12;
    t[B+1] = -1e12;
    s_rev[A] = 1e12;
    t_rev[B] = 1e12;
    s_rev[A+1] = -1e12;
    t_rev[B+1] = -1e12;

    REP(i, A) {
        cin >> s[i];
        s_rev[i] = -s[i];
    }
    REP(i, B) {
        cin >> t[i];
        t_rev[i] = -t[i];
    }
    REP(i, Q) cin >> X[i];

    sort(ALL(s));
    sort(ALL(t));

    sort(ALL(s_rev));
    sort(ALL(t_rev));

    REP(i, Q) {
        ll s1, s2, t1, t2, x = X[i];
        s1 = -*lower_bound(s_rev.begin(), s_rev.end(), -x);
        t1 = -*lower_bound(t_rev.begin(), t_rev.end(), -x);

        s2 = *lower_bound(s.begin(), s.end(), x);
        t2 = *lower_bound(t.begin(), t.end(), x);

        vector<ll> candidates(8);
        // cerr << "s1 = " << s1 << " t1 = " << t1 << " s2 = " << s2 << " t2 = " << t2 << endl;
        candidates[0] = abs(x - s1) + abs(s1 - t1); // x -> s1 -> t1;
        candidates[1] = abs(x - s1) + abs(s1 - t2); // x -> s1 -> t2;
        candidates[2] = abs(x - s2) + abs(s2 - t1); // x -> s2 -> t1;
        candidates[3] = abs(x - s2) + abs(s2 - t2); // x -> s2 -> t2;

        candidates[4] = abs(x - t1) + abs(t1 - s1); // x -> s1 -> t1;
        candidates[5] = abs(x - t1) + abs(t1 - s2); // x -> s1 -> t2;
        candidates[6] = abs(x - t2) + abs(t2 - s1); // x -> s2 -> t1;
        candidates[7] = abs(x - t2) + abs(t2 - s2); // x -> s2 -> t2;

        ll ans = 1e18;
        int arg = -1;
        REP(i, 8) {
            if (ans > candidates[i]) {
                ans = candidates[i];
                arg = i;
            }
        }
        // cerr << "arg = " << arg << endl;
        cout << ans << endl;
    }
    return 0;
}