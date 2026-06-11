#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string lcs(string s,string t,int a,int b)
{
	int i,j,k=0;
	int dp[a+1][b+1];
	for(i=0;i<=a;i++)
	dp[i][0]=0;

	for(i=0;i<=b;i++)
	dp[0][i]=0;

	for(i=1;i<=a;i++)
	{
		for(j=1;j<=b;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			
			else
			{
				dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
			}
			
		}
	}
	string ans;
	int x=0,y,z;
	i=a;j=b;
	while(i>0 && j>0)
	{
		if(s[i-1]==t[j-1])
		{
			ans.push_back(s[i-1]);
			i--;j--;
		}

		else if(dp[i-1][j]>dp[i][j-1])
		i--;
		else
		j--;
	}
	return ans;
	//cout << dp[a][b] << endl;
	//cout << ans << endl;
}

int main()
{
	string s,t;
	cin >> s >> t;
	int a,b,i,j,k;
	a=s.size();
	b=t.size();
	string ans;
	ans=lcs(s,t,a,b);
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
	return 0;
}