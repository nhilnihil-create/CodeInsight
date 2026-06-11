#include<bits/stdc++.h> 
using namespace std;

#define int long long

int M=1e9+7;


void print(vector<int>& v){
  for (int i:v) cout<<i<<" ";
    cout<<endl;
}

void printv(vector<vector<int>>& v){
	for (auto x:v) print(x);
}

void add(int &a, int b){
	a+=b;
	if (a>=M) a-=M;
}

void sub(int &a, int b){
	a-=b;
	if (a<0) a+=M;
}

signed main() {
	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	int N,K;
	cin>>N>>K;
	vector<int> candies(N+1);
	for (int i=0;i<N;i++){
		cin>>candies[i];
	}
	vector<vector<int>> dp(N+1,vector<int>(K+1));
	for (int i=0;i<=candies[0];i++) dp[0][i]=1;
	for (int i=1;i<N;i++){
		vector<int> prefix_sum(K+1,0);
		prefix_sum[0]=dp[i-1][0];
		for (int j=1;j<=K;j++){
			prefix_sum[j]=(prefix_sum[j-1]+dp[i-1][j])%M;
		}
		for (int j=0;j<=K;j++){	
			if (j>candies[i]) dp[i][j]=(M+prefix_sum[j]-prefix_sum[j-candies[i]-1])%M;
			else dp[i][j]=prefix_sum[j];
		}
	}
	cout<<dp[N-1][K];
    return 0; 
}
