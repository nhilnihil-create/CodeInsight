#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

int n,m;
vector<vector<int>> edge;
int cnt1=0,cnt2=0;
vector<int>memo;
bool flag=0;
void dfs(int par,int node,bool oe)
{
  if(flag)return;
  if(memo[node]!=-1)
  {
    if(oe!=memo[node]){flag=1;return ;}
    else return ;
  }
  if(oe)cnt1++;
  else cnt2++;
  memo[node]=(int)oe;
  for(int nn:edge[node])
  {
    if(nn!=par)
    {
      dfs(node,nn,!oe);
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  edge.resize(n+1);
  memo=vector<int>(n+1,-1);
  rep(i,m)
  {
    int a,b;
    cin>>a>>b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  dfs(-1,1,0);
  if(flag==0)
  {
    ll res=(ll)cnt1*cnt2;
    res-=m;
    cout<<res<<endl;
  }
  else
  {
    ll res=((ll)n*(n-1))/2;
    res-=m;
    cout<<res<<endl;
  }
  return 0;

}
