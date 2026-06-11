#include <bits/stdc++.h>
#define inf pow(2,60);
using namespace std;

long long dp[3001][3001];
long long sum[500][500];

long long solve(vector<int>&slimes,int i,int j){
    
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    long long minCost = inf;
    
    for(int k=i;k<j;k++){
        
        minCost = min(minCost,(sum[i][j]+solve(slimes,i,k)+solve(slimes,k+1,j)));
    }
    
    return dp[i][j] = minCost;
}

void preprocess(vector<int>&v,int n){
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j)
                sum[i][j] = v[j];
            else
                sum[i][j] = sum[i][j-1] + v[j];
        }
    }
}

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	
	vector<int> slimes(n+1);
	
	for(int i=1;i<=n;i++){
	    cin>>slimes[i];
	}

	memset(dp,-1,sizeof(dp));
	
	preprocess(slimes,n);
	
// 	for(int i=1;i<=n;i++){
// 	    for(int j=i;j<=n;j++){
// 	        cout<<sum[i][j]<<" ";
// 	    }
// 	    cout<<endl;
// 	}
	
    long long ans = solve(slimes,1,n);
    
    cout<<ans<<endl;
	
	return 0;
}
