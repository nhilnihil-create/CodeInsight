#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
string s,t;
cin>>s>>t;
vector<char> a;
int dp[s.size()+1][t.size()+1];
for(int i = 0;i<=s.size();i++)
{
	for(int j = 0;j<=t.size();j++)
	{  
	  if(i==0 || j==0)
	  {
	  	dp[i][j]=0;
	  }
		else if(s[i-1] == t[j-1])
		{
			dp[i][j]=1+dp[i-1][j-1];
			
		}
		else {
		dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		
	}
}
}
int index = dp[s.size()][t.size()];
//cout<<dp[s.size()][t.size()]<<endl;
int i =s.size(),j=t.size();
while(i>0 && j>0)
{
	    if (s[i-1] == t[j-1]) 
      { 
          a.push_back(s[i-1]); // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
}
reverse(a.begin(),a.end());	
	for(auto x : a) cout<<x;
	return 0;
}