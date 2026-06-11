#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int h,w,d;
  cin>>h>>w>>d;
  vector<pair<int,int>> mp(h*w+10);
  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      int a;
      cin>>a;
      mp[a]={i,j};
    }
  }
  auto diff=[](pair<int,int> l, pair<int,int> r){
    return abs(l.first-r.first)+abs(l.second-r.second);
  };
  unordered_map<int, int> cost;
  for (int start = 1; start <= d; ++start)
  {
    for (int i = start; i+d <= h*w ; i+=d)
    {
      cost[i+d]=cost[i]+diff(mp[i],mp[i+d]);      
    }
  }
  int q; cin>>q;
  for (int i = 0; i < q; ++i)
  {
    int l,r;
    cin>>l>>r;
    cout<<cost[r]-cost[l]<<endl;
  }

}