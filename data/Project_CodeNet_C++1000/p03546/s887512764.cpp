#include <bits/stdc++.h>
using namespace std;


int main()
{
    int h,w;
    int sum=0;
    cin>>h>>w;
  
    int dist[10][10];
    int A[h][w];
    
    for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
      {
         cin>>dist[i][j];
      }
    }
  
     for(int k=0;k<10;k++)
     {
       for(int i=0;i<10;i++)
       {
         for(int j=0;j<10;j++)
         {
             dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
         }
       }
     }
  

    for(int i=0;i<h;i++)
    {
       for(int j=0;j<w;j++)
       {
          cin>>A[i][j];
       }
    }
  
   for(int i=0;i<h;i++)
   {
     for(int j=0;j<w;j++)
     {
        if(A[i][j]!=-1)
        {
          int x=A[i][j];
          sum+=dist[x][1];  
        }
     }
   }
     

  cout<<sum<<endl;

}
