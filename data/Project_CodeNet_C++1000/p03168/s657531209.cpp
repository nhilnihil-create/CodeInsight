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
double dp[3001][3001];

double func(int i,int x,double a[]){
    if(x==0) return 1;
    if(i==0) return 0;

    if(dp[i][x] > -0.9) return dp[i][x];

    return dp[i][x]=(a[i]*func(i-1,x-1,a))+((1-a[i])*func(i-1,x,a));
}

void solve(){
	int n;
    cin>>n;
    double a[n+1];
    int c=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>a[i];
    int x=(n+1)/2;
    cout<<ps(func(n,x,a),10);
}
    

int32_t main()
{
   // FIO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();


    return 0;
}
