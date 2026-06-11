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
    vec b(N+1, 0);
    REP(i,1,N+1) cin >> b[i];

    bool f = true;
    ll s = N, k;
    vec a;
    while(s > 0) {
        k = s;
        while(k > 0 && b[k] != k) --k;
        if(k == 0) {
            f = false;
            break;
        }
        b.erase(b.begin() + k);
        --s;
        a.pb(k);
    }
    if(f) {
        REV(a);
        FORR(x,a) PR(x);
    }
    else {
        PR(-1);
    }

    return 0;
}

/*



*/