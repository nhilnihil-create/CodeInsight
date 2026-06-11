#include <bits/stdc++.h>
#define REP(i,x,y) for(int i=(int)x;i<=(int)y;i++)
#define PER(i,x,y) for(int i=(int)x;i>=(int)y;i--)
#define FOR(i,x,y) for(int i=(int)x;i< (int)y;i++)
#define fi first
#define se second
#define pb push_back
#define mk make_pair
using namespace std;
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
const   int N=200005;
const   int P=1e9+7;

char s[N];
int sum[N],n,dp[N],Mn[1<<26];

void chkmin(int &x,int y){
	if(y<x) x=y;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(Mn,0x3f,sizeof Mn);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	Mn[0]=0;
	REP(i,1,n){
		sum[i]=sum[i-1];
		sum[i]^=1<<(s[i]-'a');
	}
	
	REP(i,1,n){
		dp[i]=min(dp[i],Mn[sum[i]]+1);
		FOR(j,0,26) dp[i]=min(dp[i],Mn[sum[i]^(1<<j)]+1);
		chkmin(Mn[sum[i]],dp[i]);
	}
	
	printf("%d\n",dp[n]);
    return 0;
}