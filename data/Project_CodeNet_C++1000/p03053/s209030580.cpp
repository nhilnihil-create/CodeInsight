#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
typedef pair<int,int> P;
#define INF 10000000

int main()
{
  int h,w;cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  int i,j;
  rep(i,h)rep(j,w)cin>>a[i][j];
  vector<vector<int>> mins(h,vector<int>(w,INF));
  queue<P> q;
  rep(i,h)rep(j,w)
  {
    if(a[i][j]=='#')
    {
      mins[i][j]=0;
      q.push({i,j});
    }
  }
  queue<P> q2;
  vector<int> dh={0,1,0,-1};
  vector<int> dw={1,0,-1,0};
  while(!q.empty())
  {
    while(!q.empty())
    {
      P nowp=q.front();
      q.pop();
      int ni=nowp.first;
      int nj=nowp.second;
      rep(i,4)
      {
        int toi=ni+dh[i];
        int toj=nj+dw[i];
        if(toi<0||toi>=h||toj<0||toj>=w)continue;
        if(mins[toi][toj]==INF)
        {
          mins[toi][toj]=mins[ni][nj]+1;
          q2.push({toi,toj});
        }
      }
    }
    while(!q2.empty())
    {
      q.push(q2.front());
      q2.pop();
    }
  }
  int ans=0;
  rep(i,h)rep(j,w)ans=max(ans,mins[i][j]);
  cout<<ans<<endl;
} 
