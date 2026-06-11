#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define fo(i,start,end) for(int i=start;start<end?i<end:i>end;start<end?i+=1:i-=1)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vop vector<pll>
#define vov vector<vector<ll>>
#define endl "\n"
using namespace std;
const ld pi=3.14159265358979323;

const long long mod1=1e9+7;
const long long mod2=1e18;
const ll mod3=9e18;
const ll N=1e9+7;

long long power(ll  x, ll n){if(n==0)return 1;ll temp=power(x,n/2);if(n%2==0)return temp*temp;else return x*temp*temp;}

ll gcd(ll a,ll b){if(a<b) return gcd(b,a);if(b==0) return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/(gcd(a,b));}
void swap(int* a, int* b){int t = *a;*a = *b;*b = t;}
bool f(ll x,ll y){return x>y;}

ll MAX(ll a,ll b){return a>b?a:b;}
ll MIN(ll x,ll  y){return x>y?y:x;}

ll pmod(ll a, ll b,ll mod)//a^b%mod
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}

bool cmp2( pair<ll,ll> &a,
           pair<ll,ll> &b)
{
    return a.second>b.second;
}


void solve() {
    ll n,k;
    cin>>n>>k;
    ll arr[n+1];
    fo(i,1,n+1)cin>>arr[i];
    ll ans[k+1];
    memset(ans,0,sizeof(ans));

    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=n;j++){
            if(i-arr[j]>=0){
                if(ans[i-arr[j]]==0){
                    ans[i]=1;
                    break;
                }

            }
        }

    }


if(ans[k]==1){
    cout<<"First";
}
    else {
        cout<<"Second";
    }






}

























int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
    //freopen("error.txt" , "w" , stderr) ;
#endif








    ll t;
    t=1;
    //cin>>t;
    //  cin.ignore();
    while(t--){

        solve();
    }




    return 0;


}

////vll adj[100001];
////ll vis[100001];
////ll sssp[100001];