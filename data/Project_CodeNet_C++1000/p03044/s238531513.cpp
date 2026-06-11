
  #include<bits/stdc++.h>
  using namespace std;

  vector<pair<int,int>>dp[100005];
  int vis[100005];
  int col[100005];

  void dfs(int index)
  {
   /* if(vis[index]==1)return;
    vis[index]=1;*/
    int temp=col[index];
    for(auto it:dp[index])
    {
      if(!vis[it.first])
      {
         col[it.first]=(it.second%2==0)?temp:(temp^1);
         vis[it.first]=1;
         dfs(it.first);
      }
    }

  }



  int main()
  {


       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
     /* #ifndef ONLINE_JUDGE
          freopen("input.txt","r",stdin);
          freopen("output.txt","w",stdout);
      #endif*/
     int t;
     cin>>t;
     for(int i=0;i<t-1;i++)
     {
      int first,second,third;
      cin>>first>>second>>third;
      dp[first].push_back({second,third});
      dp[second].push_back({first,third});
     }

     for(int i=1;i<=t;i++)
     {
       if(!vis[i])
        dfs(i);
     }


     for(int i=1;i<=t;i++)
     {
      cout<<col[i]<<endl;
     }
      return 0;
      
  }