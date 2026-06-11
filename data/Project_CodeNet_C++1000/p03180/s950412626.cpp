#include<bits/stdc++.h>
#define ll long long int 
#define double /*long*/ double
#define endl '\n'
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vppll vector<pair<pll,pll>>
#define mp make_pair
#define pb push_back
#define mapll map<ll,ll>
#define fir first
#define sec second
#define _cin ios_base::sync_with_stdio(0);  cin.tie(0);
#define fo(i,b) for(i=0;i<b;i++)
#define repa(i,a,b) for(i=a;i<b;i++)
#define repb(i,a,b) for(i=a;i>=b;i--)
#define all(x) (x).begin(), (x).end()
#define s(v) v.size()
const long long int MAX = (ll)(1e18+1);
const long long int MIN = (ll)(-1e18-1);
const long long int mod = (ll)(1e9+7);
using namespace std;

ll max(ll a,ll b,ll c) {return max(max(a, b), c);}
ll min(ll a,ll b,ll c) { return min(min(a, b), c);}
ll max(ll a,ll b) {return (a>b) ? a : b;}
ll min(ll a,ll b) {return (a<b) ? a : b;}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power_mod(ll a, ll n, ll mod_){ ll p=1; while(n){ if(n%2){ p=(p*a)%mod_;} n/=2; a=(a*a)%mod_;} return p%mod_;}
                                                 /*Code Begins*/
vll ans , dp;

void rec(ll i , ll score , vll& not_taken , ll msk , ll group) {
    if(i==s(not_taken)){
        ans[msk] = max(ans[msk] , score + dp[group]);
        return;
    }
    rec(i+1 , score , not_taken , msk , group);
    rec(i+1 , score , not_taken , msk ^ (1LL<<not_taken[i]) , group ^ (1LL<<not_taken[i]));
}

int main(){

    _cin;
    // cout << setprecision(15);
    ll mn = MAX, mx = MIN;
    ll n, t, m, k, i, j,  sum=0,  prev, flag=0, cnt=0;
    ll x=0, y=0, fx, tot=0, l , r;
    int TC=1;
    // cin >> TC;
while(TC--){
    cin >> n;
    int a[n][n];
    fo(i,n) fo(j,n) cin >> a[i][j];
    dp.resize(1LL<<n , 0);
    for(ll msk =0; msk < 1LL<<n; msk++){
        dp[msk]=0;
        fo(i,n){
            if(!(msk & 1LL<<i)) continue;
            repa(j,i+1,n){
                if(msk & 1LL<<j) dp[msk] += a[i][j];
            }
        }
    }
    // cout << dp[(1LL<<n) - 1] << endl;
    ans.resize(1LL<<n,0);
    for(ll msk=0; msk < 1LL<<n; msk++){
        // for(ll msk2=0; msk2< 1LL<<n; msk2++){
        //     if((msk2 & msk) == 0LL){
        //         dp[msk2|msk] = max(dp[msk2|msk] , dp[msk2] + dp[msk]);
        //     }
        // }
        vll not_taken;
        fo(i,n) {
            if(!(msk & 1LL<<i)) not_taken.pb(i);
        }
        rec(0,ans[msk] , not_taken , msk , 0);
    }
    cout << ans[(1LL<<n) - 1];
    


    
}
    return 0;
}
