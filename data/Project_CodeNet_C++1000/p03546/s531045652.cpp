#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
int visit[10][10][10];

signed main(){
	int h,w;
	cin>>h>>w;
	int c[10][10];
	rep(i,10)rep(j,10)cin>>c[i][j];
	vector<vi> a(h,vi(w));
	rep(i,h){
		rep(j,w){
			cin>>a[i][j];
		}
	}

	vector<vi> dp(10,vi(10,INF));
	rep(i,10)rep(j,10)dp[i][j]=c[i][j];

	rep(k,10)rep(i,10)rep(j,10){
		chmin(dp[i][j],dp[i][k]+dp[k][j]);
	}

	int ans=0;
	rep(i,h)rep(j,w){
		if(a[i][j]==-1)continue;
		ans+=dp[a[i][j]][1];
	}
	cout<<ans<<endl;

	return 0;
}