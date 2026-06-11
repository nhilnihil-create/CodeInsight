#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int i,j,n,k,w,x,y,z;
  string s1,s2,s3;
  cin>>s1>>s2;
  n=s1.size();
  w=s2.size();
  vector<vector<long int>>v(n+1,vector<long int>(w+1,0));
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=w;j++)
   {
    if(s1[i-1]==s2[j-1])
     v[i][j]=1+v[i-1][j-1];
    else
     v[i][j]=max(v[i-1][j],v[i][j-1]);
   }
  }
  i=n;
  j=w;
  while(1)
  {
   if(j==0||i==0)
     break;
   else
    {
     if(s1[i-1]==s2[j-1])
     {
      s3.push_back(s1[i-1]);
      i--;
      j--;
     }
     else if(v[i][j-1]>v[i-1][j])
      j--;
     else
      i--;
    }
  }
  reverse(s3.begin(),s3.end());
  cout<<s3;
 return 0;
}