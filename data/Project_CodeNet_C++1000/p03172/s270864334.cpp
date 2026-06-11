//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;
int N,K;
int dp[101][MX];


/*int solve(int x, int y){
	if(x==R-1 && y==C-1) return 1;
	if(x<0 || y<0 || x>=R || y>=C || g[x][y]=='#') return 0;
	if(memo[x][y]!=-1) return memo[x][y];
	return memo[x][y]=(solve(x,y+1)+solve(x+1,y))%MOD;
}*/

int32_t main(){
   boost;
   IO();

   //memset(dp,-1,sizeof(dp));
   /*cin>>N>>W;
   for(int i=0; i<N;i++) cin>>w[i]>>v[i];

   for(int i=100000; i>=0; i--) if(solve(0,i)<=W){cout << i << endl; return 0;}*/

   cin>>N>>K;
   int t[N];
   for(int i=0; i<N; i++) cin>>t[i];

   for(int i=0; i<=K; i++) dp[0][i]=0;
   for(int i=K; i>=K-t[0]; i--) dp[0][i]=1;
   for(int i=1; i<=K; i++) dp[0][i]+=dp[0][i-1],dp[0][i]%=MOD;

	for(int i=1; i<N; i++) for(int j=0; j<=K; j++){
		dp[i][j]+=dp[i-1][min(K,j+t[i])];
		if(j) dp[i][j]-=dp[i-1][j-1];
		dp[i][j]=(dp[i][j]+MOD)%MOD;
		if(j<K) dp[i][j+1]+=dp[i][j]; dp[i][j+1]%=MOD;
	}

	cout << dp[N-1][0] << endl;

   return 0;
}

