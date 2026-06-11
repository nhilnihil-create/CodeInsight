#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
	
	int n;
	cin>>n;
	vector<vector<int> > comp(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>comp[i][j];
		}
	}
	vector<long long> dp(1<<n);
	dp[0]=1;
	

		for(int i=0;i<(1<<(n));i++){
			int m = __builtin_popcount(i);
			for(int w=0;w<n;w++){
				if((i&(1<<w))==0 && comp[m][w]==1){
					int j= (i|(1<<w));
					dp[j]+=dp[i];
					dp[j]%=1000000007;
				}
				
			}
		}
//	}
	
	cout<<dp[(1<<n)-1]%1000000007;
	
}