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
    map<ll,vector<pll>> Y;
    REP(i,0,M) {
        ll p, y;
        cin >> p >> y;
        Y[p].pb({y, i});
    }

    vector<pll> Z(M);
    FORR(y,Y) ASC(Y[y.first]);
    FORR(y,Y) {
        REP(i,0,SZ(y.second)) {
            ll k = y.second[i].second;
            Z[k].first = y.first;
            Z[k].second = i + 1;
        }
    }

    REP(i,0,M) {
        cout << setfill('0') << setw(6) << Z[i].first;
        cout << setfill('0') << setw(6) << Z[i].second << endl;
    }

    return 0;
}

/*



*/