#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

struct Brock{
	int w,s,v;
	bool operator<(Brock &a){
		return w+s<a.w+a.s;
	}
};
int N;
Brock A[1005];
int dp[1005][10005];
signed main(){
	cin>>N;
	rep(i,N)cin>>A[i].w>>A[i].s>>A[i].v;
	sort(A,A+N);
	rep(i,N){
		rep(j,10002){
			chmax(dp[i][j+1],dp[i][j]);
			chmax(dp[i+1][j],dp[i][j]);
			if(j<=A[i].s)
				chmax(dp[i+1][min(j+A[i].w,10001ll)],dp[i][j]+A[i].v);
		}
	}
	int ans=0;
	rep(i,10002)chmax(ans,dp[N][i]);
	cout<<ans<<endl;
}
