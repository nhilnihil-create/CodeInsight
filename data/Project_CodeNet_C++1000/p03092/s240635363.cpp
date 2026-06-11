#include "iostream"
#include "vector"

using namespace std;

int main(){
	int N,L,R;
	cin>>N>>R>>L;
	vector<int>v(N);
	for(auto &i:v)cin>>i;
	vector<int>place(N+1);
	for(int i=0;i<N;i++){
		place[v[i]]=i;
	}
	vector<vector<long long int>>dp(2,vector<long long int>(N+2));
	for(int i=1;i<=N;i++){
		int index =i&1;
		long long int box=dp[index^1][0];
		for(int j=0;j<=N+1;j++){
			box=min(box,dp[index^1][j]);
			if(place[i]+1>j)dp[index][j]=box+L;
			else if(place[i]+1==j)dp[index][j]=box;
			else dp[index][j]=box+R;
		}
	}
	long long int ans=1000000000000000000;
	for(int i=0;i<=N+1;i++)ans=min(ans,dp[N&1][i]);
	cout<<ans<<endl;
}