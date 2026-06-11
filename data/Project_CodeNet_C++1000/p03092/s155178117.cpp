#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define upd(x, y) x=min(x, y)

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=5010, LOG=20;

int n, m, k, u, v, x, y, t, A, B;
int P[MAXN], PP[MAXN];
ll dp[MAXN][MAXN], ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, 63, sizeof(dp));
	cin>>n>>A>>B;
	for (int i=1; i<=n; i++) cin>>P[i], PP[P[i]]=i;
	dp[0][0]=0;
	for (int i=0; i<n; i++) for (int j=0; j<=i; j++){
		if (PP[j]<PP[i+1]) upd(dp[i+1][j], dp[i][j]+B);
		if (PP[j]>PP[i+1]) upd(dp[i+1][j], dp[i][j]+A);
		if (PP[j]<PP[i+1]) upd(dp[i+1][i+1], dp[i][j]);
	}
	ans=INF;
	for (int i=0; i<=n; i++) upd(ans, dp[n][i]);
	cout<<ans<<'\n';
	
	return 0;
}
