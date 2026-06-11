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
// vector<int>adj[100005];
// int dp[100005];
// bool vis[100005];
// int in_degree[100005];
// void dfs(int src){
//     vis[src]=true;    
//     for(auto it:adj[src]){
//         dp[it]=max(dp[it],dp[src]+1);
//         --in_degree[it];
//         if(in_degree[it]==0)dfs(it);
//         }
//
//
//
// }
//
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
       ll int a[n];
        fo(i,n){
            cin>>a[i];
        }
        auto sum =[&](int L,int R){
        ll int s=0;
            
            for(int i=L;i<=R;i++){
            s+=a[i];
            }
            return s;
        };
        for(int L=n-1;L>=0;L--){
            for(int R=L;R<n;R++){
                if(L==R){
                    dp[L][R]=0;
                }
                else{
                    dp[L][R]=INF;
                    ll int s=sum(L,R);
                for(int i=L;i<=R-1;i++){
                dp[L][R]=min(dp[L][R],dp[L][i]+dp[i+1][R]+s);
                }
            }
            }
        }
        cout<<dp[0][n-1];
            
}
}
