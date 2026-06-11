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
    ll N, M;
    cin >> N >> M;
    vec A(M), B(M);
    REP(i,0,M) {
        cin >> A[i] >> B[i];
        --A[i]; --B[i];
    }

    ll cnt = 0;

    REP(i,0,M) {
        
        mat G(N);
        REP(j,0,M) {
            if(i == j) continue;
            G[A[j]].pb(B[j]);
            G[B[j]].pb(A[j]);
        }

        queue<ll> Q;
        vector<bool> F(N, false);
        Q.push(0);
        F[0] = true;
        while(!Q.empty()) {
            ll v = Q.front(); Q.pop();
            FORR(nv,G[v]) {
                if(!F[nv]) {
                    F[nv] = true;
                    Q.push(nv);
                }
            }
        }

        bool f = true;
        REP(j,0,N) {
            if(!F[j]) {
                f = false;
                break;
            }
        }
        if(!f) ++cnt;

    }

    PR(cnt);

    return 0;
}

/*



*/