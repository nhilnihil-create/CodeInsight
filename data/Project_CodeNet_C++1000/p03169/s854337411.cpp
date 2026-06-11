#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define int long long
#define fi first
#define se second
#define ncr(n,r) fact[n]*modInv(fact[r])*modInv(fact[n-r])
#define modInv(a) binExp(a,mod-2)
#define mod 1000000007
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define os_find(k) find_by_order(k)
#define os_order(k) order_of_key(k)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define make_graph(k) int x,y; f0(i,0,k){cin>>x>>y; adj[x].pb(y); adj[y].pb(x);}
#define test int t;cin>>t;while(t--)

double dp[301][301][301];
double expected[301][301][301];

signed main()
{
    fast

    #ifndef ONLINE_JUDGE
        freopen("inputf.in","r",stdin);
        freopen("outputf.in","w",stdout);
    #endif

    int n;
    cin>>n;

    int x;
    vector<int> cnt(4);
    f0(i,0,n)
    {
    	cin>>x;
    	cnt[x]++;
    }


    
    f1(i,0,n) f1(j,0,n) f1(k,0,n) dp[i][j][k] = expected[i][j][k] = 0;

    dp[cnt[1]][cnt[2]][cnt[3]] = 1;
    f3(k,n,0)
    {
    	f3(j,n,0)
    	{
    		f3(i,n,0)
    		{
    			if(i==0 && j==0 && k==0 || (i+j+k) > n) continue;

    			double probWaste = (double) (n - (i+j+k)) / n;
    			double expWaste = probWaste / (1 - probWaste) + 1;

    			expected[i][j][k] += expWaste * dp[i][j][k];

    			if(k!=0)
    			{
    				double p = (double) k / (i+j+k);
    				dp[i][j+1][k-1] += dp[i][j][k] * p;
    				expected[i][j+1][k-1] += (expected[i][j][k]) * p;
    			}
    			

    			if(j!=0)
    			{
    				double p = (double) j / (i+j+k);
    				dp[i+1][j-1][k] += dp[i][j][k] * p;
    				expected[i+1][j-1][k] += (expected[i][j][k]) * p;
    			}
    			

    			if(i!=0)
    			{
    				double p = (double) i / (i+j+k);
    				dp[i-1][j][k] += dp[i][j][k] * p;
    				expected[i-1][j][k] += (expected[i][j][k]) *p;
    			}
    		}
    	}
    }

    cout<<fixed<<setprecision(10)<<expected[0][0][0];
}