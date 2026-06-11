
/*Author-Ayush Tiwari
JAI_SHREE_RAM         */

#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define debug(x) cout<<"debug--->>"<<" "<<x<<endl
#define eb emplace_back
#define eps 1e-6
# define M_PI  3.14159265358979323846
#define vll vector<long long int>
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
typedef long long int ll;

// some fantestic operations
  
 
 //----------------------------------------------------------------------------------------------------------
   ll M=1e9+7;
    ll mod(ll x){
        return ((x%M + M)%M);
    }
    ll add(ll a, ll b){
        return mod(mod(a)+mod(b));
    }
    ll mul(ll a, ll b){
        return mod(mod(a)*mod(b));
    }
 
    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }

//---------------------------------------------------------------------------------------------
vll a(100002);
vll dp(100002,-1);
//ll n;

void solve()
{
	ll n;
	cin>>n;
	ll i;
	for(i=0;i<n;i++)
		cin>>a[i];
	dp[0]=0;
	dp[1]=abs(a[1]-a[0]);

	for(i=2;i<n;i++)
	{
		dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
	}

  // solve2(n);
cout<<dp[n-1];


}
int main(){
    FAST;
        #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
#endif
ll t;
//cin>>t;
//while(t--){
	
	solve();
//}
}