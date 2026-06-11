    #include<bits/stdc++.h>
    using namespace std;
     
    int mi[4]={-1,0,1,0};
    int mj[4]={0,-1,0,1};
     
    int main()
    {
      int H,W;scanf("%d %d",&H,&W);
      char S[H][W];string ans="Yes";  
      bool check[H][W];for(int i=0;i<H;i++)fill(check[i],check[i]+W,false);
      for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>S[i][j];
      for(int i=0;i<H;i++)for(int j=0;j<W;j++)
      {
        if(check[i][j]||S[i][j]=='.')continue;
        queue<pair<int,int>> que;
        que.push({i,j});
        int count=1;
        while(!que.empty())
        {
          int I=que.front().first,J=que.front().second;que.pop();
          for(int k=0;k<4;k++)
          {
            int mI=I+mi[k],mJ=J+mj[k];
            if(mI<0||mI>H-1||mJ<0||mJ>W-1)continue;
            if(S[mI][mJ]=='.'||check[mI][mJ])continue;
            check[mI][mJ]=true;count++;
            que.push({mI,mJ});
          }
        }
        if(count==1)ans="No";
      }
      cout<<ans<<endl;
    }