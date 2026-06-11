#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm( a, b ) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair< int, int > P;
typedef pair< LL, LL > LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

LL fac[SIZE], finv[SIZE], inv[SIZE];
void combInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for( int i = 2; i < SIZE; ++i ) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;

    }
}

LL comb(int n, int k) {
    if( n < k ) return 0;
    if( n < 0 || k < 0 ) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;

}

vector< int > Div( int n ) {
    vector< int > ret;
    for( int i = 1; i * i <= n; ++i ) {
        if( n % i == 0 ) {
            ret.pb( i );

            if( i * i != n ) ret.pb( n / i );
        }
    }
    sort( all( ret ) );
    return ret;
}

int imos[SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    vector< pair<int, P> > v;
    for( int i = 0; i < n; ++i ) {
        int s, t, c;
        cin >> s >> t >> c;
        v.pb(MP(c, MP(s, t)));

    }
    sort(all(v));

    for( int i = 0; i < n; ++i ) {
        if( i - 1 >= 0 ) {
            if( v[i - 1].F == v[i].F && v[i - 1].S.S == v[i].S.F ) {
                imos[v[i].S.F + 1]++;

            } else {
                imos[v[i].S.F]++;

            }
        } else {
            imos[v[i].S.F]++;

        }
        imos[v[i].S.S + 1]--;
    }

    int res = 0;
    int cnt = 0;
    for( int i = 0; i <= 100005; ++i ) {
        cnt += imos[i];
        res = max(res, cnt);

    }
    cout << res << endl;
    return 0;
}

