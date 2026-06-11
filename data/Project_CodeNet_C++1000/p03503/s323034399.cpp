#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N;
    cin >> N;
    mat F(N, vec(10));
    mat P(N, vec(11));
    REP(i,0,N) {
        REP(j,0,10) cin >> F[i][j];
    }
    REP(i,0,N) {
        REP(j,0,11) cin >> P[i][j];
    }

    ll m = -INF, sum = 0;
    vector<bool> G(10);
    vec C(N);
    REP(i,1,1<<10) {
        REP(j,0,10) G[j] = (((i >> j) & 1) == 1);
        sum = 0;
        REP(j,0,N) {
            C[j] = 0;
            REP(k,0,10) C[j] += (F[j][k] && G[k]);
            sum += P[j][C[j]];
        }
        m = MAX(m,sum);
    }
    PR(m);

    return 0;
}

/*



*/