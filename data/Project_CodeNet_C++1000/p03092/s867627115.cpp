/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=5005;
int n,A,B;
int a[maxn];
ll dp[maxn][maxn];
bool have[maxn];

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d%d",&n,&A,&B);
	REP(i,n)scanf("%d",&a[i]);
	REP(i,n){
		int cnt=0;
		REP(j,n){
			if(j>a[i])cnt+=have[j];
			if(a[i]>j)dp[i][j]=dp[i-1][j];
			else{
				dp[i][j]=dp[i-1][j]+(cnt?B:0);
				dp[i][j]=min(dp[i][j],dp[i-1][a[i]]+1LL*cnt*A);
			}
		}
		have[a[i]]=true;
	}
	printf("%lld\n",dp[n][n]);
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/
