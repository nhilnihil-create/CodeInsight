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
    ll Q;
    cin >> Q;
    vec L(Q), R(Q);
    REP(i,0,Q) cin >> L[i] >> R[i];

    ll N = 100000;
    vec F(N+1, true);
    F[0] = false;
    F[1] = false;
    for(ll i=2; i*i<=N; ++i) {
        if(F[i]) {
            for(ll j=2*i; j<=N; j+=i) {
                F[j] = false;
            }
        }
    }

    vec G(N+1);
    for(ll i=1; i<=N; i+=2) G[i] = F[i] & F[(i+1)/2];
    vec C(N+1, 0);
    REP(i,0,N) C[i+1] = C[i] + G[i+1];

    REP(i,0,Q) PR(C[R[i]]-C[L[i]-1]);

    return 0;
}

/*



*/