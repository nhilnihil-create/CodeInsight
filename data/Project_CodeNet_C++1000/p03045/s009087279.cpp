#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

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
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    ll N, M;
    cin >> N >> M;
    mat G(N);
    REP(i,0,M) {
        ll x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    vec F(N+1, false);
    queue<ll> Q;
    ll k = 0, cnt = 0;
    Q.push(0);
    F[0] = true;
    while(k < N) {
        while(!Q.empty()) {
            ll v = Q.front(); Q.pop();
            FORR(nv,G[v]) {
                if(!F[nv]) {
                    Q.push(nv);
                    F[nv] = true;
                }
            }
        }
        while(k < N && F[k]) ++k;
        Q.push(k);
        F[k] = true;
        ++cnt;
    }
    PR(cnt);

    return 0;
}

/*



*/