#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long lo;
typedef pair< lo,lo > PII;

#define fi first
#define se second
#define mp make_pair
#define int long long
#define endl "\n"
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo inf = 1000000000000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 100002;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,dp[li][5];
int cev;
string s;
vector<int> v[li];

inline int add(int x,int y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}

inline int mul(int x,int y){
	return (x%mod)*(y%mod)%mod;
}

inline void dfs(int node,int ata){
	int sum[2]={1,1};
	flag=0;
	for(int i=0;i<(int)v[node].size();i++){
		int go=v[node][i];
		if(go==ata)continue;
		flag=1;
		dfs(go,node);
		sum[0]=mul(sum[0],add(dp[go][0],dp[go][1]));
		sum[1]=mul(sum[1],dp[go][0]);
	}
	if((int)v[node].size()==1 && ata!=0){
		dp[node][0]=1;
		dp[node][1]=1;
	}
	else{dp[node][0]=sum[0];dp[node][1]=sum[1];}
}

main(void){
	//~ memset(dp,-1,sizeof(dp));
	scanf("%lld",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld %lld",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	printf("%lld\n",add(dp[1][1],dp[1][0]));
	return 0;
}

