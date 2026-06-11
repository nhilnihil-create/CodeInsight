#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

constexpr lint mod=1e9+7;

int main()
{
	string S;
	cin >> S;

	lint dp[100010][4]={};
	dp[0][0]=1;

	for(int i=0;i<S.size();i++)
	{
		for(int j=0;j<4;j++)
		{
			if(S[i]=='?')dp[i+1][j]+=dp[i][j]*3;
			else dp[i+1][j]+=dp[i][j];
			dp[i+1][j]%=mod;
		}

		if(S[i]=='A' || S[i]=='?')dp[i+1][1]+=dp[i][0];
		dp[i+1][1]%=mod;
		if(S[i]=='B' || S[i]=='?')dp[i+1][2]+=dp[i][1];
		dp[i+1][2]%=mod;
		if(S[i]=='C' || S[i]=='?')dp[i+1][3]+=dp[i][2];
		dp[i+1][3]%=mod;
	}

	cout << dp[S.size()][3] << endl;
	return 0;
}
