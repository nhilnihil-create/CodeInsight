#include<bits/stdc++.h> 
using namespace std;

#define int long long
void print(vector<int>& v){
  for (int i:v) cout<<i<<" ";
    cout<<endl;
}
void printv(vector<vector<int>>& dp){
	for (auto x:dp) print(x);
}
int M=1e18+5;

int solve(vector<int>& slimes, int i, int j, vector<vector<int>>& dp){
	auto sum=[&](int L, int R){
		int s=0;
		for (int i=L;i<=R;i++) s=(s%M+slimes[i]%M)%M;
		return s;
	};
	if (i>=j) return 0;
	if (dp[i][j]!=-1) return dp[i][j];
	int s=sum(i,j);
	int ans=M;
	for (int k=i;k<j;k++){
		int left = solve(slimes,i,k,dp);
		int right = solve(slimes,k+1,j,dp);
		ans=min(ans,(left%M+right%M+s%M)%M);
	}
	return dp[i][j]=ans%M;
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	int N;
	cin>>N;
	vector<int> slimes(N);
	for (int i=0;i<N;i++){
		cin>>slimes[i];
	}
	vector<vector<int>>dp(N+1,vector<int>(N,-1));
	cout<<solve(slimes,0,N-1,dp)<<endl;
    return 0; 
}

/*
*/