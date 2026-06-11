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
    vector<vector<pair<ll,ll>>> G(N);
    REP(i,0,N-1) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        G[u].eb(v, w%2);
        G[v].eb(u, w%2);
    }

    queue<ll> Q;
    vector<ll> F(N, -1);
    Q.push(0);
    F[0] = 0;
    while(!Q.empty()) {
        ll v = Q.front(); Q.pop();
        FORR(ne,G[v]) {
            ll nv = ne.first, val = ne.second;
            if(F[nv] == -1) {
                if(val == 1) F[nv] = 1 - F[v];
                else F[nv] = F[v];
                Q.push(nv);
            } 
        }
    }

    REP(i,0,N) PR(F[i]);

    return 0;
}

/*



*/