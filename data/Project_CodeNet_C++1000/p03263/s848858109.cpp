#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h,w;
  cin>>h>>w;
  vector<vector<int> >a(h);
  vector<vector<int> >vis(h);
  for(int i=0;i<h;i++)
  {
    a[i].resize(w);
    vis[i].resize(w);
    for(int j=0;j<w;j++)cin>>a[i][j];
  }
  vector< pair<int,int> >from;
  vector< pair<int,int> >to;
  
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      if(a[i][j]%2==1)
      {
        if(i!=0 && a[i-1][j]%2!=0)
        {
          a[i][j]--;
          a[i-1][j]++;
          from.push_back({i,j});
          to.push_back({i-1,j});
        }
        else if(j!=0 && a[i][j-1]%2!=0)
        {
          a[i][j]--;
          a[i][j-1]++;
          from.push_back({i,j});
          to.push_back({i,j-1});
        }
        else if(i!=h-1 && a[i+1][j]%2!=0)
        {
          a[i][j]--;
          a[i+1][j]++;
          from.push_back({i,j});
          to.push_back({i+1,j});
        }
        else if(j!=w-1 && a[i][j+1]%2!=0)
        {
          a[i][j]--;
          a[i][j+1]++;
          from.push_back({i,j});
          to.push_back({i,j+1});
        }
        else 
        {
          if(j!=w-1)
          {
            a[i][j]--;
          	a[i][j+1]++;
          	from.push_back({i,j});
          	to.push_back({i,j+1});
          }
          else if(i!=h-1)
          {
            a[i][j]--;
          	a[i+1][j]++;
          	from.push_back({i,j});
          	to.push_back({i+1,j});
          }
        }
      }
    }
  }
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      if(a[i][j]%2==0)
      {
        vector<pair<int,int> >t;
        if(i!=0 && a[i-1][j]%2!=0)
        {
          t.push_back({i-1,j});
        }
        
        if(j!=0 && a[i][j-1]%2!=0)
        {          
          t.push_back({i,j-1});
        }
        
        if(i!=h-1 && a[i+1][j]%2!=0)
        {       
       		t.push_back({i+1,j});      
        }
        
        if(j!=w-1 && a[i][j+1]%2!=0)
        {       
          t.push_back({i,j+1});  
        }
        if(t.size()>=2)
        {
          a[t[0].first][t[0].second]--;
          from.push_back(t[0]);
          to.push_back({i,j});
          
          a[t[1].first][t[1].second]--;
          from.push_back(t[1]);
          to.push_back({i,j});
        }
        if(t.size()==4)
        {
          a[t[2].first][t[2].second]--;
          from.push_back(t[2]);
          to.push_back({i,j});
          
          a[t[3].first][t[3].second]--;
          from.push_back(t[3]);
          to.push_back({i,j});
        }
    }
  }
 }
  cout<<from.size()<<endl;
  for(int i=0;i<from.size();i++)
  {
    cout<<from[i].first+1<<" "<<from[i].second+1<<" "<<to[i].first+1<<" "<<to[i].second+1<<endl;
  }
  return 0;
}