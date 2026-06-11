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

LL dp[256][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    LL k;
    cin >> n >> k;
    vector< LL > v(n);
    for( int i = 0; i < n; ++i ) {
        cin >> v[i];

    }


    int bi_cnt[256] = {};
    int bi = 0;
    for( int i = 0; i < n; ++i ) {
        LL tmp = v[i];
        int bic = 0;
        while( tmp > 0 ) {
            bi_cnt[bic] += tmp & 1;
            tmp >>= 1;
            bic++;

        }
        bi = max(bi, bic);

    }

    int bic = 0;
    LL tmp = k;
    while( tmp > 0 ) {
        tmp >>= 1;
        ++bic;

    }
    bi = max(bi, bic);

    // dp[i][j] : iビット目を適切なビットにしたときに得られる最大の数
    for( int i = bi - 1; i >= 0; --i ) {
        if( i == bi - 1 ) {
            if( ((1ll << i) & k) > 0 ) {
                dp[i][0] = (1ll << i) * bi_cnt[i];
                dp[i][1] = (1ll << i) * (n - bi_cnt[i]);

            } else {
                dp[i][0] = 0;
                dp[i][1] = (1ll << i) * bi_cnt[i];
            }

        } else {
            dp[i][1] = dp[i + 1][1];
            if( ((1ll << i) & k) > 0 ) {
                dp[i][1] += (1ll << i) * (n - bi_cnt[i]);

            } else {
                dp[i][1] += (1ll << i) * bi_cnt[i];

            }

            if( ((1ll << i) & k) > 0 ) {
                if( dp[i + 1][1] > dp[i + 1][0] ) {
                    if( bi_cnt[i] > n / 2 ) {
                        dp[i][0] = dp[i + 1][1];
                        dp[i][0] += (1ll << i) * bi_cnt[i];

                    }
                }
            }

            if( dp[i + 1][0] == 0 ) continue;
            LL t = (1ll << i) * bi_cnt[i];
            LL s = (1ll << i) * (n - bi_cnt[i]);
            if( t < s ) {
                dp[i][0] = max(dp[i][0], dp[i + 1][0] + s);

            } else {
                dp[i][0] = max(dp[i][0], dp[i + 1][0] + t);

            }
        }
    }

    cout << max(dp[0][1], dp[0][0]) << endl;
    return 0;
}

