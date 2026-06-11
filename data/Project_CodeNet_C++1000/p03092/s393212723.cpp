#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

int N;
ll A,B;
int p[5010],where[5010];
ll dp[5010][5010];
const ll inf = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
	cin >> N >> A >> B;
	rep(i,N) cin >> p[i],p[i]--,where[p[i]] = i;

	rep(i,N+1) rep(j,N+1) dp[i][j] = inf;

	dp[0][0] = 0;
	rep(i,N){
		rep(j,N+1) if(dp[i][j] != inf){
			if(j != N){
				chmin(dp[i][j+1],dp[i][j]);
			}
			if(p[i] == j){
				chmin(dp[i+1][j+1],dp[i][j]);
			}
			if(p[i] < j){
				chmin(dp[i+1][j],dp[i][j] + B);
			}
			if(p[i] > j){
				chmin(dp[i+1][j],dp[i][j] + A);
			}
		}
	}
	ll ans = inf;
	rep(j,N+1) chmin(ans,dp[N][j]);
	cout << ans << endl;
}
