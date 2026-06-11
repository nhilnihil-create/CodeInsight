#include<bits/stdc++.h>
using namespace std;
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define IOS  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
#define F first
#define S second	
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define LCM(a,b) (a*b)/__gcd(a,b)
#define mii map<int,int>
#define mll map<ll,ll>
#define ub upper_bound
#define lb lower_bound
#define sz(x) (ll)x.size()
#define ld long double
#define pcnt(x) __builtin_popcountll(x)
const long long I1=1e9;
const long long I2=1e18;
const int32_t M1=1e9+7;
const int32_t M2=998244353;
template<typename T,typename T1>T maxn(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T minn(T &a,T1 b){if(b<a)a=b;return a;}
int n;
ld dp[301][301][301];
/*ld f(int p, int q,int r)
{
    if(p==0 && q==0 && r==0) return 0;
    ld x,val1=0,val2=0,val3=0;
    if(p>0)
    {
    x=(ld)(p)/(p+q+r);
    if(dp[p-1][q][r]==0) dp[p-1][q][r]=f(p-1,q,r);
    val1= (p==0?0:x*dp[p-1][q][r]);
    }
    if(q>0)
    {
    x=(ld)(q)/(p+q+r);
    if(dp[p+1][q-1][r]==0) dp[p+1][q-1][r]=f(p+1,q-1,r);
    val2= (q==0?0:x*dp[p+1][q-1][r]);
    }
    if(r>0)
    {
    x=(ld)(r)/(p+q+r);
     if(dp[p][q+1][r-1]==0) dp[p][q+1][r-1]=f(p,q+1,r-1);
    val3= (r==0?0:x*dp[p][q+1][r-1]);
    }
   // cout<<val1<<" "<<val2<<" "<<val3<<endl;
    ld ans=(ld)(n)/(p+q+r)+val1+val2+val3;
   // if(p==1) cout<<ans<<endl;
    return ans;
}*/
void solve()
{
  //code begins from here//
    cin>>n;
    int a[4]={0};
    lop (i,n)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    lop(k,a[3]+1)
    {
        lop(j,a[2]+1+a[3]-(k))
        {
            lop(i,a[1]+1+a[2]+a[3]-(k+j))
            {
                if(i==j && j==k && i==0) continue;
                dp[i][j][k]=(ld)(n)/(i+j+k);
                if(i) dp[i][j][k]+=((ld)(i)/(i+j+k))*dp[i-1][j][k];
                if(j) dp[i][j][k]+=((ld)(j)/(i+j+k))*dp[i+1][j-1][k];
                if(k) dp[i][j][k]+=((ld)(k)/(i+j+k))*dp[i][j+1][k-1];
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dp[a[1]][a[2]][a[3]]<<endl;
}

signed main()
{
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef MODULO
        initialize();
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    int testcase=1;
   // cin>>testcase;
    while(testcase--) solve();
    return 0;
}
