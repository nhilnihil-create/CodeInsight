#include<bits/stdc++.h>
using namespace std;
long long int mod=1000000007;
int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<long long int>>grid(H,vector<long long int>(W,0));
    char a;
    for(int i=0;i<H;i++)
     for(int j=0;j<W;j++)
     {
         cin>>a;
         if(a=='#')
          grid[i][j]=-1;
        //cout<<grid[i][j]<<" ";
     }
    
    for(int i=0;i<H;i++){
        if(grid[i][0]==-1)
         break;
     grid[i][0]=1;}
    for(int i=0;i<W;i++){
        if(grid[0][i]==-1)
         break;
     grid[0][i]=1;}
    grid[0][0]=1;
    for(int i=1;i<H;i++)
    {
        for(int j=1;j<W;j++)
        {  if(grid[i][j]!=-1){
            if(grid[i-1][j]!=-1 && grid[i][j-1]!=-1)
             {grid[i][j]=grid[i-1][j]+grid[i][j-1];
              if(grid[i][j]>mod)
               grid[i][j]%=mod;}
            else if(grid[i-1][j]!=-1 && grid[i][j-1]==-1)
             grid[i][j]=grid[i-1][j];
            else
             grid[i][j]=grid[i][j-1];}
        }
    }
    /*for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
         cout<<grid[i][j]<<" ";
        cout<<endl;
    }*/
    if(grid[H-1][W-1]==-1)
     cout<<0<<endl;
    else
    cout<<grid[H-1][W-1]%mod<<endl;

  

}