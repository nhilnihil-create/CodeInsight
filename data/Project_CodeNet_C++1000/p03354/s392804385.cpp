#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define N 100000
vector<int> par(N);
vector<int> ranks(N);

void init(int n)
{
  int i;
  rep(i,n)
  {
    par[i]=i;
    ranks[i]=1;
  }
}

int find(int x)
{
  if(par[x]==x)return x;
  else return par[x]=find(par[x]);
}

void unite(int x, int y)
{
  x=find(x);
  y=find(y);
  if(x==y)return;
  if(ranks[x]<ranks[y])par[x]=y;
  else
  {
    par[y]=x;
    if(ranks[x]==ranks[y])ranks[x]++;
  }
}

bool same(int x, int y)
{
  return find(x) == find(y);
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> p(n);
  int i;
  rep(i,n)cin>>p[i];
  vector<int> pos(n);
  rep(i,n)pos[p[i]-1]=i;
  vector<int> x(m);
  vector<int> y(m);
  rep(i,m)cin>>x[i]>>y[i];
  init(n);
  rep(i,m)
  {
    unite(pos[x[i]-1],pos[y[i]-1]);
  }
  int ans=0;
  rep(i,n)
  {
    if(same(pos[i],i))ans++;
  }
  cout<<ans<<endl;
}
