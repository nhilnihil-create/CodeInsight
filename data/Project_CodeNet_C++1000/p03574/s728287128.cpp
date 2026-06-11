#include<iostream>
using namespace std;
int main (void)
{
  int h,w,l,i,j,k;
  string s[50];
  char ns[100][100];
  int ans[51][51];
  
  cin>>h>>w;
  for(i=0;i<h;i++)
  {
    cin>>s[i];
  }
   
  for(i=0;i<w+2;i++)
  {
    ns[0][i]='.';
    ns[h+1][i]='.';
  }
  
  for(i=0;i<h;i++)
  { 
    ns[i+1][0]='.';
    ns[i+1][w+1]='.';
    
    
    for(j=0;j<w;j++)
    {
      ns[i+1][j+1]=s[i][j];
    }
  }
  
  for(i=1;i<=h;i++)
  {
    for(j=1;j<=w;j++)
    {
      ans[i][j]=0;
      
      for(k=i-1;k<=i+1;k++)
      {
        for(l=j-1;l<=j+1;l++)
        {
          if(ns[k][l]=='#')ans[i][j]++; 
        }   
      }
       if(ns[i][j]=='#')cout<<"#";
       else cout<<ans[i][j];   
    }
    cout<<endl;
  }    
}