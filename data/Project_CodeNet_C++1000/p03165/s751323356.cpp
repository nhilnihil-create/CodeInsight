#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int 
using namespace std; 
ll dp[3004][3004];
string solve1(string a,string b,int i,int j)
{
  string v;
 
  while(i>0 && j>0)
  {
    if(a[i-1]==b[j-1])
    {
      
     
      v.push_back(a[i-1]);
      i--;
     j--;
    }
    else
    {
      if(dp[i-1][j]>=dp[i][j-1])
      {
        i--;
      }
      else
      {
        j--;
      }
      
    }
    
  }
  return v;

}
int main() 
{ 
  FastIO;
  string a;
  string b;
  cin>>a>>b;
  
  for(ll i=0;i<=a.length();i++)
  {
    dp[i][0]=0;
  }
  for(ll i=0;i<=b.length();i++)
  {
    dp[0][i]=0;
  }
  for(int i=1;i<=a.length();i++)
  {
    for(int j=1;j<=b.length();j++)
    {
      if(a[i-1]==b[j-1])
      {
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else
      {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
      
    }
  }
  string s=solve1(a,b,a.size(),b.size());
  reverse(s.begin(),s.end());
  cout<<s;
} 
