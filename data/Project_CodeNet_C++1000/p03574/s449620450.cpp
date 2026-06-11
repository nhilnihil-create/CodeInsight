#include<bits/stdc++.h>
using namespace std;

int mx[8]={-1,-1,-1,0,0,1,1,1},my[8]={1,0,-1,1,-1,1,0,-1};

int main()
{
  int H,W;scanf("%d %d",&H,&W);
  char S[H][W];
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>S[i][j];
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)
  {
    if(S[i][j]=='#')continue;
    int count=0;
    for(int k=0;k<8;k++)
    {
      int x=j+mx[k],y=i+my[k];
      if(x<0||y<0||x>=W||y>=H)continue;
      if(S[y][x]=='#')count++;
    }
    S[i][j]='0'+count;
  }
  for(int i=0;i<H;i++){for(int j=0;j<W;j++)cout<<S[i][j];cout<<endl;}
}