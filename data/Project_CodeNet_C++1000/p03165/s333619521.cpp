#include <bits/stdc++.h>

using namespace std;

string lcs_backtrack(string a, string b) {
	int l1=a.size();
  	int l2=b.size();

  int dp[l1+1][l2+1];

  for (int i=0;i<=l1;i++)
  {
  	for (int j=0;j<=l2;j++)
  	{
  		if (i==0||j==0) dp[i][j]=0;
	  		else if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
  				else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
  		}
  	}

  int k=dp[l1][l2];
  string result(k,'\0');

  int i=l1,j=l2;
   while(i>0 && j>0){

		if (a[i-1]==b[j-1])
		{
			k--;
			result[k]=a[i-1];
			i--;
			j--;
		}
		else if (dp[i][j-1]<dp[i-1][j]) i--;
		else j--;
  	}

  return result;
}

int main() {
 
 string a,b;
 cin >> a >> b;
 cout << lcs_backtrack(a, b) ;

} 
