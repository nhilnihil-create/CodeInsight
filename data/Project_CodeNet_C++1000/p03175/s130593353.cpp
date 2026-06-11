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

vector<vi> edges(100005,vi());
ll dp[100005][2];

ll dfs(int i, int color, int parent)
{
    if(dp[i][color] != -1) return dp[i][color];

    ll res = 1;
    for(int j: edges[i])
    {
        if(j==parent) continue;
        if(color == 0) res = mult(res, add(dfs(j,0,i), dfs(j,1,i)));
        else res = mult(res, dfs(j,0,i));

    }

    return dp[i][color] = res;
}


void solve()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    rep(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
   }

   //0 for white, 1 for black
   ll ans = add(dfs(1,0,-1),dfs(1,1,-1));
   cout<<ans;
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