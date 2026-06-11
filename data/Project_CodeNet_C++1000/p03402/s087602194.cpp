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

int mp[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    for( int i = 51; i <= 100; ++i ) {
        for( int j = 1; j <= 100; ++j ) {
            mp[i][j] = 1;

        }
    }

    int black = 1, white = 1;
    int he = 1, wi = 1;
    // 0 : white  1: black
    while( he <= 49 && black != b ) {
        wi = 1;
        while( wi <= 100 && black != b ) {
            mp[he][wi] = 1;
            ++black;
            wi += 2;
        }
        he += 2;
    }

    he = 100; wi = 1;
    while( he >= 51 && white != a ) {
        wi = 1;
        while( wi <= 100 && white != a ) {
            mp[he][wi] = 0;
            ++white;
            wi += 2;

        }
        he -= 2;

    }

    cout << "100 100" << endl;
    for( int i = 1; i <= 100; ++i ) {
        for( int j = 1; j <= 100; ++j ) {
            if( mp[i][j] == 1 ) {
                cout << '#';

            } else {
                cout << '.';

            }
        }
        cout << endl;
    }
    return 0;
}

