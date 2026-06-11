#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000


int main(){
	
	int N;
	cin>>N;
	
	vector<vector<long long>> a(N,vector<long long>(N,0));
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>a[i][j];
		}
	}
	
	vector<vector<int>> ind(N+1,vector<int>());
	
	vector<long long> num(1<<N,0LL);
	
	for(int i=0;i<(1<<N);i++){
		vector<int> X;
		for(int j=0;j<N;j++){
			if((1<<j)&i){
				X.push_back(j);
			}
		}
		ind[X.size()].push_back(i);
		
		for(int j=0;j<X.size();j++){
			for(int k=j+1;k<X.size();k++){
				num[i] += a[X[j]][X[k]];
			}
		}
	}
	
	vector<long long> dp(1<<N,-Inf);
	dp[0] = 0;
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<ind[i].size();j++){
			int x = ind[i][j];
			do{
				dp[ind[i][j]] = max(dp[ind[i][j]],dp[x]+num[x^ind[i][j]]);
				x = (x-1)&ind[i][j];
			}
			while(x!=ind[i][j]);
		}
	}
	
	cout<<dp.back()<<endl;
	
    return 0;
}
