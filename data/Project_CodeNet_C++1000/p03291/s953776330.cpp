#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

//return x^y mod p
ll power(ll x,ll y, ll p)
{
    if (y < 0) return 0;
    ll res = 1;     
    x = x % p; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s; cin>>s; int n = s.size();
    ll res = 0, acnt = 0, ccnt = 0, qcnt = 0, qtot = 0;
    FOR(i, 0, n) {
        ccnt += (s[i] == 'C');
        qtot += s[i] == '?';
    }
    FOR(i, 0, n) {
        if (s[i] == 'B' || s[i] == '?') {
            ll tota = (acnt * power(3, qcnt, MOD))%MOD + (qcnt * power(3, qcnt - 1, MOD))%MOD;
            ll rqcnt = qtot - qcnt - (s[i] == '?');
            ll totc = (ccnt * power(3, rqcnt, MOD))%MOD + (rqcnt * power(3, rqcnt - 1, MOD))%MOD;
            res += (tota * 1LL * totc) % MOD;
            res %= MOD;
        }
        acnt += s[i] == 'A';
        ccnt -= s[i] == 'C';
        qcnt += s[i] == '?';
    }
    cout << res;
    return 0;
}