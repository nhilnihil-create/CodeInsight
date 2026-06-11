//Bismillahirrahmanirrahim
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

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

int n,m,b[li],a[li],k,flag,t,dp[102][li];
int cev;
string s;
vector<int> v;

inline int add(int x,int y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}

main(void){
	//~ memset(dp,-1,sizeof(dp));
	scanf("%lld %lld",&n,&k);
	FOR{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		cev=0;
		for(int j=1;j<=a[i];j++){
			cev=add(cev,dp[i-1][j]);
			dp[i][j]=add(cev,1);
		}
		for(int j=a[i]+1;j<=k;j++){
			cev=add(cev,mod-dp[i-1][j-a[i]-1]);
			cev=add(cev,dp[i-1][j]);
			//~ cout<<cev<<endl;
			dp[i][j]=cev;
		}
		
	}
	dp[n][0]=1;
	printf("%lld\n",dp[n][k]);
	return 0;
}

