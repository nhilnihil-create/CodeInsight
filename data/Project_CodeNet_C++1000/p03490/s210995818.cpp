#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ld long double
#define pb push_back
#define pll pair<ll, ll> 
#define tri pair<pll, ll>
#define vl vector<ll> 
#define vvl vector< vector<ll> > 
#define vlp vector< pair<ll, ll> >
#define vllp vector<pair<pll, ll> > 
#define mll map<ll, ll> 
#define rep(i,a)  for(ll i=0; i< a; i++)
#define rep1(i,a)   for(ll i = 1; i< a; i++)
#define foi(i, a, b)    for(ll i = a; i<b ; i++)
#define fod(i, a, b)    for(ll i = a; i>=b ; i--)
#define mp make_pair
#define all(v)  (v).begin(), (v).end()
#define fst first
#define sec second
#define ff first.first
#define fs first.second
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define MAX 1000001
#define MOD 1000000007
// #define MOD 998244353
#define endl "\n"
#define INF (ll)1e18
#define s(v) (ll)v.size()
#define e(v) v.empty()
#define bscount(x) __builtin_popcountll(x)
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
// using namespace __gnu_pbds;

ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll cpow(ll a, ll b, ll M){ll ans = 1;while(b){if(b&1) ans = ans*a%M; b/=2;a=a*a%M;}return ans;}
void ingraph(vvl& graph, ll m){ll x, y;rep(i, m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}
ll modify(ll n){ll res = n;res%=MOD;res+=MOD;res%=MOD;return res;}
ll fexp(ll a, ll b) {return cpow(a, b, MOD);}
ll cinv(ll a, ll p){return cpow(a, p-2, p);} 
ll inverse(ll a)    {return cinv(a, MOD);}

bool dp[2][20000];
ll N = 8000;

bool can(vl& vec, ll x, ll id){
    dp[1][N] = 1;
    ll n = s(vec);
    ll idx = 0;
    rep(i, n){
        rep(j, 2*N + 1){
        	dp[idx][j] = 0;
            if(j - vec[i] >= 0)  dp[idx][j] |= dp[1-idx][j-vec[i]];
            if((id || i) && j + vec[i] <= 2*N)   dp[idx][j] |= dp[1-idx][j+vec[i]];
        }
        idx = 1-idx;
   		if(!i)	dp[1][N] = 0;
    }
    return dp[1-idx][x+N];
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    // cin>>t;
    t = 1;
    while(t--){
        string str;
        cin>>str;
        ll u, v;cin>>u>>v;
        ll n = s(str);
        vl v1, v2;
        ll cur = 0;
        bool x = 0;
        rep(i, n){
            if(str[i] == 'F')   cur++;
            else{
                if(x)   v2.pb(cur);
                else v1.pb(cur);
                x ^= 1;
                cur = 0; 
            }
        }
        if(x)   v2.pb(cur);
        else v1.pb(cur);
        // for(ll v : v1)  cout<<v<<" ";cout<<endl;
        if(can(v1, u, 0)){
            rep(i, 20000)   dp[0][i] = 0, dp[1][i] = 0;
            if(can(v2, v, 1))  cout<<"Yes";
            else cout<<"No";
        }else cout<<"No";
    }
}
