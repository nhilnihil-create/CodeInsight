/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;*/
#include<algorithm>
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define vi vector<ll>
#define pii pair<ll,ll>
#define bc __builtin_popcountll
#define vvi vector<vi> 
#define vpii vector<pair<ll,ll>>
#define mll unordered_map<ll,ll>
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
#define fo(i,a,b) for(i=a;i<=b;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<=n;i++)
#define fb(i,n) for(ll i=n-1;i>=0;i--)
#define fb1(i,n) for(ll i=n;i>0;i--)
#define endd cout<<'\n';
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define clr(x) memset(x, 0.00, sizeof(x))
#define sortall(x) sort(all(x))
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define CASES  ll t;cin>>t;while(t--)
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
//*X.find_by_order()-->returns an iterator to the k-th largest element (counting from zero)
//X.order_of_key()-->the number of items in a set that are strictly smaller than our item.
struct cmp
{
	bool operator() (ll a,ll b){
		return (a>b);
	}
};
ll ceil(const ll &a, const ll &b)
{
    if(a%b == 0)
        return a/b;
    return a/b +1;
}
ll mod=1000000007;
const ll N=100005;
int main()
{
fast;
    ll n;
    cin>>n;
    long double p[n];
    f(i,n)
    {
        cin>>p[i];
    }
    long double dp[n+1][n+1];//dp[i][j]=probablity of getting j heads till ith index our ans=dp[n][i](i=n/2+1 to n)
    clr(dp);
    dp[0][0]=1.00;
    f1(i,n)
    {
        f(j,i+1)
        {
            if(j==0)//0 heads
            {
                dp[i][j]=dp[i-1][j]*(1.0-p[i-1]);
                continue;
            }
            dp[i][j]=(dp[i-1][j-1]*p[i-1])+(dp[i-1][j]*(1.00-p[i-1]));
        }
    }
    //more heads then tail start from n/2+1
    long double ans=0.0;
    for(ll i=(n/2)+1;i<=n;i++)
    {
        ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}