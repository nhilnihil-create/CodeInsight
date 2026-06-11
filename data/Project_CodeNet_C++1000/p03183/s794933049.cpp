#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)>>1)
#define all(x) x.begin(),x.end()
#define dbgs(x) cerr<<(#x)<<" --> "<<(x)<<" "
#define dbg(x) cerr<<(#x)<<" --> "<<(x)<<endl;getchar()
#define pw(x) (1<<(x))
#define inf 1000000000000005
#define MOD 1000000007
#define N 10005
#define M 27000
#define LOG 1000000
#define KOK 650
#define EPS 0.000000001
using namespace std;

struct reyiz {

	int w,s,v;

} r[N];

int n;
ll dp[2][N];

int main() {

	//freopen("input.txt","r",stdin);	

	scanf("%d",&n);

	for(int i=1;i<=n;i++) {

		scanf("%d %d %d",&r[i].w,&r[i].s,&r[i].v);

	}

	sort(r+1,r+1+n,[](reyiz a,reyiz b) {

		return a.w+a.s<b.w+b.s;

	});

	for(int j=0;j<=10001;j++) dp[1][j]=dp[0][j]=-inf;

	dp[1][0]=0;

	for(int i=1;i<=n;i++) {

		bool cur=i&1;
		bool nx=!cur;

		for(int j=0;j<=10001;j++) {

			umax(dp[nx][j],dp[cur][j]);

			if(j<=r[i].s) {

				umax(dp[nx][min(10001,j+r[i].w)],dp[cur][j]+r[i].v);

			}

			dp[cur][j]=-inf;

		}

	}

	ll ans=-inf;

	for(int i=0;i<=10001;i++) {

		umax(ans,dp[!(n&1)][i]);

	}

	printf("%lld",ans);

}
