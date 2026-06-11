#include <bits/stdc++.h>

using namespace std;

typedef long long               ll;
typedef long double             ld;

#define min3(a, b, c)           min((a), min((b), (c)))
#define max3(a, b, c)           max((a), max((b), (c)))
#define lcm(a,b)                (a / __gcd(a,b) ) *b
#define gcd(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define sqr(a)                  ((a)*(a))
#define urs(r...)               typename decay<decltype(r)>::type
#define FOR(i,a,b)              for(urs(b) i=a;i<b;i++)
#define ROF(i,a,b)              for(urs(b) i=a;i>=b;i--)
#define REP(a,b)                for(urs(b) i=a;i<b;i++)
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define all(a)                  a.begin(),a.end()
#define vi                      vector <int> 
#define pi                      pair <int, int> 
#define SORT(v)                 sort(v.begin(), v.end());
#define FASTIO                  ios_base::sync_with_stdio(0);cin.tie(NULL);
#define PI                      acos(-1.0)
#define nl                      "\n"
const int MOD = 1e9 + 7;

ll fast_pow (ll n, ll p)
{
    ll res=1;
    while (p>0)
    {
        if (p&1)
            res = res * n;
        p = p>>1;
        n = n * n;
    }
    return res;
}

ll BMod(ll B,ll P,ll M)
{
    ll R=1;
    B=B%M;
    while(P)
    {
        if(P&1)
            R=(R*B)%M;
        P >>= 1;
        B=(B*B)%M;
    }
    return R;
}

ll invMOD(ll num,ll M)
{
    return BMod(num,M-2,M);
}

//use this, if overflow happens
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t m)
{
    if (a > b)
        swap (a, b);

    uint64_t res = 0;
    uint64_t temp_b;

    if (b >= m)
    {
        if (m > UINT64_MAX / 2u)
            b -= m;
        else
            b %= m;
    }

    while (a != 0)
    {
        if (a & 1)
        {    
            if (b >= m - res)
                res -= m;
            res += b;
        }
        a >>= 1;

        temp_b = b;
        if (b >= m - b)
            temp_b -= m;
        b += temp_b;
    }
    return res;
}

#ifdef Sieve
const int pSz = 50005;
bool np[pSz + 10]; vi prime; int prime_size;
void sieve(){np[0] = np[1] = 1;prime.pb(2);
for(ll i = 4; i <= pSz; i+=2) np[i] = 1;
for(ll i = 3; i <= pSz; i+=2){if(!np[i]){prime.pb(i);
for(ll j = i * i; j <= pSz; j += (i << 1)) np[j] = 1;}}prime_size = prime.size();}
#endif

#ifdef Combi
const int nSz = 2000006;
ll F[nSz + 1], tMod = MOD;
void Factorial(){ F[0] = 1; for(int i = 1; i <= nSz; i++) F[i] = (F[i - 1] * i) % tMod; }
inline ll nCr(int n, int r) { if(n < r) return 0; return (F[n] * invMOD((F[n - r] * F[r]) % tMod, tMod)) % tMod; }
 
#endif
 
#ifdef Z_Algo
void zAlgo(char *s, int *z){
    int L, R, sz; sz = strlen(s); z[0] = L = R = 0;
    FOR(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); 
    while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}void zAlgo(string &s, int *z){
    int L, R, sz; sz = s.size(); z[0] = L = R = 0;
    FOR(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); 
    while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}void zAlgo(int *s, int *z, int n){
    int L, R, sz; sz = n; z[0] = L = R = 0;
    FOR(i, 1, sz) { z[i] = 0; if(i <= R) z[i] = min(z[i - L], R - i + 1); 
    while(i + z[i] < sz && s[i + z[i]] == s[z[i]]) z[i]++; if(i + z[i] - 1 > R) L = i, R = i + z[i] - 1; }
}
#endif


//////////////////////////////////////////////////////////////////////////////
///                           M. K. BASHAR                                 ///
///                            IUT CSE'18                                  ///
//////////////////////////////////////////////////////////////////////////////
int n, one, two, three;
ld dp[301][301][301];

ld call(int o, int tw, int th)
{
    if (o < 0 || tw < 0 || th < 0)
        return 0;
    
    if (o == 0 && tw == 0 && th == 0)
        return 0;

    if (dp[o][tw][th] > 0)
        return dp[o][tw][th];

    int rem = o+tw+th;

    ld ex_val = n + o  * call (o-1, tw, th)
                  + tw * call(o+1, tw-1, th)
                  + th * call (o, tw+1, th-1);
    return dp[o][tw][th] = ex_val / rem;
}

int main()
{    
    cin >> n;
    int buf = 0;
    one = 0;
    two = 0;
    three = 0;

    REP (0, n)
    {
        cin >> buf;
        if (buf  == 1)  one++;
        else if (buf == 2) two++;
        else    three++;
    }

    memset (dp, -1, sizeof (dp));
    ld ans = call (one, two, three);

    cout << fixed << setprecision(9) << ans;
    return 0;
}