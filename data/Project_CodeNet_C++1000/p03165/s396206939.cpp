#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  int l1 = s1.length();
  int l2 = s2.length();
  int dp[l1+1][l2+1];
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=l1;i++)
  {
    for(int j=1;j<=l2;j++)
    {
      	if(s1[i-1]!=s2[j-1])
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        else
          dp[i][j] = 1+dp[i-1][j-1];
        }
    }
   /* for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
     int i = l1, j=l2;
     string s = "";
     while(i>0&&j>0)
     {

     if( s1[i-1]==s2[j-1])
	 {
       s += s1[i-1];
       i--,j--;
     }
	 else if(dp[i-1][j]>dp[i][j-1])
     i--;
       else
         j--;
     }
     reverse(s.begin(),s.end());
      cout<<s<<endl;
           return 0;
           
  
}