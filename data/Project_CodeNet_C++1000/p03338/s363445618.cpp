#include<iostream>
using namespace std;
int main(void)
{
  int i,j,k,l,n,left[26],right[26],same,ans;
  string s,sl,sr;
  cin>>n;
  cin>>s;
  ans=0;
  for(i=1;i<n-1;i++)
  {  
    same=0;
   for(j=0;j<26;j++)
   {
     left[j]=0;right[j]=0;
   }
    
   for(j=0;j<n;j++)
   {
     if(j<i)
     {
       left[s[j]-'a']=1;
     }
     else
     {
       right[s[j]-'a']=1;
     }
   }
   for(j=0;j<26;j++)
   {
     if(left[j]==1&&right[j]==1){same++;}
   }
   if(same>ans){ans=same;}
  }
  
  cout<<ans;
  
  
}