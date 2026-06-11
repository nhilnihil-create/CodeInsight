#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(i=1;i<=n;i++)
#define rep(i,k,n) for(i=k;i<=n;i++)
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ps(x,y) cout<<fixed<<setprecision(y)<<x<<endl
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}


int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS

    ll n,i,j;
    cin>>n;
    ll score[n+1][n+1];
    fr(i,n)
        fr(j,n)
            cin>>score[i][j];

    ll dp[(1<<n)+1];

    rep(i,0,(1<<n)-1)
    {
        vll temp;
        for(j=0;j<n;j++)
        {
            if((1<<j)&i)
                temp.eb(j+1);
        }
        dp[i]=0;
        for(auto u: temp)
            for(auto v:temp)
                dp[i]+=score[u][v];
        dp[i]/=2;
    }
    rep(i,0,(1<<n)-1)
    {
        for(ll j=i;j>0;j=(j-1)&i)
        {
            dp[i]=max(dp[i],dp[j]+dp[i^j]);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;

    return 0;  
}

