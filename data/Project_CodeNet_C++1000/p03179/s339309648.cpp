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
    string s;
    cin >> s;
    ll dp[n+2][n+2];
    vll pr(n+2,0);
    fo(i,n+2) {
        fo(j,n+2) dp[i][j]=-1;
        // cout << endl;
    }
    dp[1][1]=1;
    pr[0]=0;
    pr[1]=1;
    repa(l,2,n+1){
        repa(i,1,l+1){
            if(s[l-2]=='<') {
                dp[l][i] = pr[i-1]%mod;
            }else{
                dp[l][i] = (pr[l-1] +mod - pr[i-1])%mod;
            }
        }
        pr[0]=0;
        repa(i,1,l+1) pr[i] = (pr[i-1] + dp[l][i])%mod;
        // pr[l+1]=pr[l];
    }
    ll ans=0;
    repa(i,1,n+1) ans = (ans + dp[n][i])%mod;
    cout << ans << endl;
    // repa(i,1,n+1) {
    //     repa(j,1,n+1) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }



}
    return 0;
}
