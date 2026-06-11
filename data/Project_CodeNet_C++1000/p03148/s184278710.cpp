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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector< P > v;
    for( int i = 0; i < n; ++i ) {
        int t, d;
        cin >> t >> d;
        v.pb(MP(d, t));

    }
    sort(all(v), greater< P >());

    map< int, int > mp;
    priority_queue< P > pq;
    vector< P > vv;
    priority_queue< P, vector< P >, greater< P > > sel;
    LL fin = 0;
    LL res = 0;
    for( int i = 0; i < n; ++i ) {
        if( mp[v[i].S] != 0 || sel.size() == k ) {
            pq.push(v[i]);

        } else {
            ++fin;
            res += v[i].F;
            sel.push(v[i]);
            mp[v[i].S]++;

        }
    }

    if( sel.size() < k ) {
        while( !pq.empty() && sel.size() < k ) {
            P p = pq.top(); pq.pop();
            sel.push(p);
            mp[p.S]++;
            res += p.F;

        }

        while( !pq.empty() ) {
            P p = pq.top(); pq.pop();
            P sel_min = sel.top(); sel.pop();
            if( mp[sel_min.S] > 1 ) break;
            
            LL tmp = res - sel_min.F;
            tmp += p.F;
            if( res + fin * fin < (fin - 1) * (fin - 1) + tmp ) {
                --fin;
                res = tmp;
                mp[p.S]++;
                mp[sel_min.S]--;
                sel.push(p);

            } else {
                break;

            }
        }
        
    } else {
        while( !pq.empty() ) {
            P p = pq.top(); pq.pop();
            P sel_min = sel.top(); sel.pop();
            if( mp[p.S] == 0 ) {
                sel.push(sel_min);
                continue;

            }
            
            LL tmp = res - sel_min.F;
            tmp += p.F;
            if( mp[sel_min.S] == 1 ) {
                if( res + fin * fin < (fin - 1) * (fin - 1) + tmp ) {
                    mp[sel_min.S]--;
                    mp[p.S]++;
                    res = tmp;
                    --fin;
                    sel.push(p);
                    
                } else {
                    sel.push(sel_min);

                }
            } else {
                sel.push(sel_min);

            }
        }
    }
    cout << fin * fin + res << endl;
    return 0;
}

