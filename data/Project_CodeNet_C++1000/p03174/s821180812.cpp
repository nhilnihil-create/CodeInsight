#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,s,e) for(int i=s;i<=e;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX (int)1e9 + 99
#define maxof(a,b,c) max(a,max(b,c))
#define minof(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pa pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define bitcnt(x) __builtin_popcount(x)
#define gcd(a,b) __gcd(a,b)
#define all(x) (x).begin(),(x).end()
#define ts(x) to_string(x)
#define set0(x) memset(x, 0, sizeof(x))
const double pi = 3.14159265358979323846;
ll binpow(ll, ll);
ll mult(ll, ll);
ll add(ll , ll);
ll division(ll, ll);
ll nCr(ll, ll);
ll inv(ll);
void calc();
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is;}
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) {if (!v.empty()) {os << v.front();for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];} return os;}
const int N=50010;
//ll fact[N];

void solve()
{
    int n;
    cin>>n;
    vector<vi> arr(n, vi(n));


    rep(i,n)
    {
        rep(j,n)
        cin>>arr[i][j];
    }

    vi dp(1<<n);
    dp[0] = 1;

    for(int mask = 0; mask < (1<<n)-1; mask++)
    {
        int a = bitcnt(mask);
        rep(b,n)
        {
            if(arr[a][b] & !(mask & (1<<b)))
            {
                int x = mask ^ (1<<b);
                dp[x] = add(dp[x], dp[mask]);
            }
        }


    }


    cout<<dp[(1<<n)-1];
}

int main()
{
    fastio;
    
    int t=1;
    //cin>>t;
    
    rep(i,t)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}

ll add(ll a, ll b){
    a+=b;
    while(a>=MOD) a-=MOD;
    while(a<0) a+=MOD;
    return a;
}

ll mult(ll a, ll b){
    return (a * 1ll * b) % MOD;
}


ll binpow(ll a, ll b){
    ll c = 1;
    while(b > 0)
    {
        if(b % 2 == 1)
            c = mult(c, a);
        a = mult(a, a);
        b /= 2;
    }
    return c;   
}

ll inv(ll a){
    return binpow(a, MOD-2);
}

ll division(ll a, ll b){
    return mult(a, inv(b));
}

/*ll nCr(ll n, ll r){
    if(r > n) return 0;
    return division(fact[n], mult(fact[n-r], fact[r]));
}

void calc(){
    fact[0] = 1;
    srep(i,1,N-1)
        fact[i] = (i*1ll*fac[i-1])%MOD;

}*/