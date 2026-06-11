#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl;
#define dd(x) cout<<#x<<"="<<x<<" ";
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b,t) for(int i=a;i<(b);i+=t)
#define ll long long
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define mp(u,v) make_pair(u,v)
#define sz(a) a.size()
#define ull unsigned long long
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define qc std::ios::sync_with_stdio(false)
const int mod = 1e9+7;
const int maxn = 8e3+5;
const double EPS = 1e-6;
using namespace std;
int base = 8000;
char s[maxn];
int a[maxn];
int dp[2*maxn],g[2*maxn];
int main()
{
	int x,y;
	scanf("%s",s+1);
	scanf("%d%d",&x,&y);
	int len = strlen(s+1);
	int d = 0,cnt = 0;
	rep(i,1,len+1){
		if(s[i]=='F') d++;
		else a[++cnt] = d, d = 0;
	}
	if(d) a[++cnt] = d;
	dp[base] = 1;
	repp(i,1,len+1,2){
		if(i==1) {
			dp[base] = 0;
			dp[base+a[i]] = 1;
			continue;
		}
		rep(j,0,2*base+1) if(dp[j]) g[j-a[i]]=g[j+a[i]]=1;
		rep(j,0,2*base+1) dp[j]=g[j],g[j]=0;
	}
	if(!dp[x+base]) return puts("No"),0;
	mt(dp,0);dp[base]=1;
	repp(i,2,len+1,2){
//		if(i==2) {
//			dp[base] = 0;
//			dp[base+a[i]] = 1;
//			continue;
//		}
		rep(j,0,2*base+1) if(dp[j]) g[j-a[i]]=g[j+a[i]]=1;
		rep(j,0,2*base+1) dp[j]=g[j],g[j]=0;
	}
	if(!dp[y+base]) return puts("No"),0;
	puts("Yes");
	return 0;
}

