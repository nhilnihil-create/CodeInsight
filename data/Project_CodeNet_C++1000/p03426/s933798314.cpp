#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts

int main()
{
  int h,w,d;cin>>h>>w>>d;
  vector<vector<int>> a(h,vector<int>(w));
  vector<int> x(h*w+1,-1);
  vector<int> y(h*w+1,-1);
  int i,j;
  rep(i,h)rep(j,w)cin>>a[i][j];
  int q;cin>>q;
  vector<int> l(q);
  vector<int> r(q);
  rep(i,q)cin>>l[i]>>r[i];
  vector<int> cost(h*w+1,0);
  rep(i,h)rep(j,w)
  {
    x[a[i][j]]=i;
    y[a[i][j]]=j;
  }
  for(i=d+1;i<=h*w;i++)
  {
    cost[i]=cost[i-d]+abs(x[i]-x[i-d])+abs(y[i]-y[i-d]);
  }
  rep(i,q)cout<<cost[r[i]]-cost[l[i]]<<endl;
}
