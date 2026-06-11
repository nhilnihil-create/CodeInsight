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
int dp[1001][1001];



void solve(){
	int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        if(a[i][0]=='#') dp[i][0]=0;
        else dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<m;i++){
        if(a[0][i]=='#') dp[0][i]=0;
        else dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]!='#') dp[i][j]=(dp[i][j-1] + dp[i-1][j])%mod;
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
}
    

int32_t main()
{
    //FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
