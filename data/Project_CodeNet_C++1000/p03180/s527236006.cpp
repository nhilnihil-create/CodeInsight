#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N;
int a[16][16];
int memo[1<<16];
int dp[1<<16];
signed main() {
	cin>>N;
	rep(i,N)rep(j,N)cin>>a[i][j];
	rep(i,1<<N)rep(j,N)if(i>>j&1)rep(k,N)if(i>>k&1)memo[i]+=a[j][k];
	rep(i,1<<N){
		for(int j=i;j>0;j=(j-1)&i){
			chmax(dp[i],dp[i-j]+memo[j]);
		}
	}
	cout<<dp[(1<<N)-1]/2<<endl;
}
