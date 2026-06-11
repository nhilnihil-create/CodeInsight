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
    vec k(M);
    mat s(M);
    REP(i,0,M) {
        cin >> k[i];
        REP(j,0,k[i]) {
            ll _s;
            cin >> _s;
            s[i].pb(_s);
        }
    }
    vec p(M);
    REP(i,0,M) cin >> p[i];

    ll cnt = 0;
    REP(i,0,1<<N) {
        bool f = true;
        REP(j,0,M) {
            ll c = 0;
            FORR(sw,s[j]) c += (i >> (sw-1) & 1);                
            if(c % 2 != p[j]) f = false;
        }
        if(f) ++cnt;
    }
    PR(cnt);

    return 0;
}

/*



*/