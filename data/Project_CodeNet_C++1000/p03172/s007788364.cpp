#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp12            make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pq1             priority_queue<int>
#define pqr1            priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void FIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int modInv(int a,int b,int m){int res=1;a=a%m;while(b>0){if(b&1){res=(res*a)%m;}a=(a*a)%m;b=b>>1;}return res;}



void solve(){
	int n,k, i,j, ans;
    cin >> n >> k;
 
    int a[n+1];
 
    for (i = 1; i <= n; i++)
        cin >> a[i];
 
    vector<vector<int>> dp(n + 2, vector<int>(k + 2));
 
    for(j=0;j<=k;j++)
        dp[1][j]=(j>a[1])?0:1;
 
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j] = (dp[i][j-1]+dp[i-1][j] - ( (j-a[i]-1 >=0)? dp[i-1][j-a[i]-1]:0)+mod)%mod;
        }
    }
 
    ans=dp[n][k];
    cout << ans << endl;
}
    

int32_t main()
{
    //FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
