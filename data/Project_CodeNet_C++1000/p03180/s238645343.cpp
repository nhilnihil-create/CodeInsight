#include <bits/stdc++.h>
using namespace std;
long long n,val[16][16],sums[(1<<16)],dp[(1<<16)];

void tryy(int curr , int mk , int mask){
	if(curr == n){
		dp[mask^mk] = max(dp[mask^mk],dp[mask]+sums[mk]);
		return ;
	}
	tryy(curr+1,mk,mask);
	if(mask & (1 << curr)){
		tryy(curr+1,mk^(1<<curr),mask);
	}
}

void getsum(int mask){
	vector<int> pos;
	for(int i = 0 ; i < n ; i += 1){
		if(mask & (1 << i)){
			pos.push_back(i);
		}
	}
	long long ret = 0;
	for(int i = 0 ; i+1 < pos.size() ; i += 1){
		for(int j = i+1 ; j < pos.size() ; j += 1){
			ret += val[pos[i]][pos[j]];
		}
	}
	sums[mask] = ret;
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i += 1){
		for(int j = 0 ; j < n ; j += 1){
			cin >> val[i][j];
		}
	}
	for(int i = 1 ; i < (1<<n) ; i += 1){
		getsum(i);
	}
	for(int i = (1<<n)-1 ; i > 0 ; i -= 1){
		tryy(0,0,i);
	}
	cout << dp[0] << endl;
}