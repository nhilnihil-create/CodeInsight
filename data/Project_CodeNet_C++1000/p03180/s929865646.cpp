#include <bits/stdc++.h> 
using namespace std;
const int mxn = 17 , N = 5e5 + 5 , mod = 1e9 + 7;
long long grid[mxn][mxn];
long long value[1<<17];
int arr[mxn];
long long calc(int idx){
	long long ret = 0; 
	for(int i = 0; i < idx ; i++){
		for(int j = i + 1 ; j < idx ; j++){
			ret += grid[arr[i]][arr[j]];
		}
	}
	return ret;
}
long long dp[1<<mxn];
bitset<(1<<mxn)>vis;
long long solve(long long mask){
	if(vis[mask])return dp[mask];
	vis[mask] = true;
	long long ret = value[mask] ;
	for(int i = mask ; i ; i = (i - 1) & mask){
		ret = max(ret  , solve(i) + value[mask ^ i]);
	}
	return dp[mask] = ret;
}
int main(){
	int n ;
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n ; j++){
			cin>>grid[i][j];
		}
	}
	for(int i=  0; i < (1<<16) ; i++){
		int pl = 0;
		for(int j = 0; j < n ;j++){
			if(i & (1 << j))
				arr[pl++] = j;
		}
		value[i] = calc(pl);
	}
	cout<<solve((1<<n) - 1)<<endl;
	return 0;
}
