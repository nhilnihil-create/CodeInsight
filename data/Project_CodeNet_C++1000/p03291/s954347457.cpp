#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9+5)
#define INFLL ((LL)4e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;

int main(){
	string str;
	cin>>str;
	int N = str.size();
	vector<int>line(N);
	REP(i, N){
		if('A'<=str[i]&&str[i]<='C')line[i]=str[i]-'A';
		else line[i]=3;
	}
	vector<vector<LL>> dp(N+1, vector<LL>(4, 0));
	dp[N][3]=1;
	PER(i, N){
		if(line[i]==3)dp[i][3]=3*dp[i+1][3]%MOD;
		else dp[i][3]=dp[i+1][3];
	}
	PER(i, N){
		PER(j, 3){
			if(line[i]==3){
				dp[i][j]=dp[i+1][j+1]+3*dp[i+1][j];
			}else if(line[i]==j){
				dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
			}else{
				dp[i][j]=dp[i+1][j];
			}
			dp[i][j]%=MOD;
		}
	}
	cout<<dp[0][0]<<endl;
	return 0;
}
