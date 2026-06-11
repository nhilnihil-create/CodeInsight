
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int         long long
#define ll          long long
#define ld	    long double
#define pb          push_back
#define pp	    pop_back()
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define mp          make_pair
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),a.rend()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repj(j,a,b) for(ll j=a;j<b;j++)
#define lexistr(x,y)      lexicographical_compare(x.begin(),x.end(),y.begin(),y.end())
#define IOS	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//CONSTANTS----------------------------------
#define PI 	    3.141592653589793238462643
const ll hell=1000000007;
const ll mod=1000000007;
//CODE------------------------------------------
ll solve()
{
    ll n; cin>>n;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    ll dp[n];
    dp[0]=0;
    dp[1]=abs(a[0]-a[1]);
    for(ll i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n-1];
    return 0;
}
//MAIN------------------------------------------
signed main(){
    IOS
    #ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
        cout<<endl;
    }
    return 0;
}
