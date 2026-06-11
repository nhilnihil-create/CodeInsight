#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
//	string str=lcs(s,t,"");
//	cout<<str<<"\n";
  int m=s.size(),n=t.size();
	vector<vector<int> >dp(m+1,vector<int>(n+1,0));
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i-1]==t[j-1])
			   dp[i][j]=dp[i-1][j-1]+1;
			else
			{
				if(dp[i-1][j]>=dp[i][j-1])
				   dp[i][j]=dp[i-1][j];
				else
				   dp[i][j]=dp[i][j-1];
				  
			}
		}
	}
  int index=dp[m][n];
  string x="";
  int i=m,j=n;
  while(i>0 && j>0)
  {
    if(s[i-1]==t[j-1]){
      x=s[i-1]+x;
      i--;
      j--;
    }
    else if(dp[i-1][j]>dp[i][j-1])
      i--;
    else
      j--;
  }
	cout<<x<<"\n";
	
}
