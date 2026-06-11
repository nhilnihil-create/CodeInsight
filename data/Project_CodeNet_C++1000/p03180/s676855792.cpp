/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 17;

void add(ll &a, ll b){
    a += b; 
}


int main(){
    FIN;
    ll n;
    cin >> n;
    vi dp(1 << n, -inf), sum(1 << n, 0);
    dp[0] = 0;
    ll a[n + 3][n + 3];
    forn(i,n){
        forn(j,n){
            cin >> a[i][j];
        }
    }

    forn(b, 1 << n)
    {
        forn(f, n)
        {
            forn(s, n)
            {
                if (((1 << f) & b) && ((1 << s) & b))
                {
                    add(sum[b], a[f][s]);
                }
            }
        }
        sum[b] >>= 1;
    }

    forn(i, 1<<n){
        ll x = (1<<n)-1-i;
        ll b = 0;
        do
        {
            // process subset b
            ll actSum = sum[b];

            dp[i|b] = max(dp[i|b], actSum + dp[i]);
        } while ((b = ((b - x) & (x))));
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}

