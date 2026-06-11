#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp);
void ipgraph(int m);
//void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
const ll INF=1e18L+5;
ll int dp[2090][3000];   
int main(){
ios_base::sync_with_stdio(0);
ll int t,n,i,j,k,m;
t=1;

// cin>>t;
int T;
Fo(T,1,t+1){
//  cout<<"Case #"<<T<<": ";
     cin>>n;
     int a[n][n];
     fo(i,n){
         fo(j,n){
             cin>>a[i][j];
         }
     }
     vector<int>dp(1<<n);
     dp[0]=1;
     for(int mask=0;mask<(1<<n)-1;mask++){
         int aa=__builtin_popcount(mask);
         for(int b=0;b<n;b++){
             if(a[aa][b]&&!(mask&(1<<b))){
                 int m=mask^(1<<b);
                 dp[m]=(dp[m]%mod+dp[mask]%mod)%mod;
             }
         }
     }
     cout<<dp[(1<<n)-1]%mod;
}
}
