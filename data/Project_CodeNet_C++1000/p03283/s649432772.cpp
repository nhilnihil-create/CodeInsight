/*
给一个长度n 编号 1-n 的数组， m个操作， 每次操作选定 [L,R] 搞一次， q个查询，
每次查询问[L,R] 严格子区间内，搞了几回 。
例如: 操作 [1,1] [2,2] [1,2] , [1,6] 查询[1 2] 得到3
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666
int n,m,q;
int dp[N][N],mp[N][N]={0};
/*
dp(i,j): 区间 [i,j] 覆盖的子区间的数量
dp(l,r)+=dp(l,r-1)+dp(l+1,r)-dp(l-1,r-1) 
*/
signed main(){
	cin>>n>>m>>q;
	int l,r;
	for(int i=0;i<m;i++){
		cin>>l>>r;
		mp[l][r]++;
	}
	for(int l=n;l>=1;l--){
		for(int r=l;r<=n;r++){
			dp[l][r]=mp[l][r]+dp[l][r-1]+dp[l+1][r]-dp[l+1][r-1];
		}
	}
	while(q--){
		cin>>l>>r;
		cout<<dp[l][r]<<'\n';
	}
	return 0;
}