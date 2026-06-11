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
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

struct edge{int to,cost;};
struct dijkstra
{
  using P=pair<int,int>;
  priority_queue<P,vector<P>,greater<P>> q;
  vector<vector<edge>>ed;
  vector<int>dist;
  int sz;
  dijkstra(int size){
    sz=size;
    ed.resize(size);
  }
  void reset(){
    dist.assign(sz,-1);
    q=priority_queue<P,vector<P>,greater<P>>();
  }
  void ae(int from,int to,int cost){
    ed[from].push_back({to,cost});
  }
  int cal(int start,int end=0){
    reset();
    q.push({0,start});
    while(!q.empty()){
      P tp=q.top();q.pop();
      if(dist[tp.second]!=-1)continue;
      dist[tp.second]=tp.first;
      for(auto nn:ed[tp.second]){
        if(dist[nn.to]!=-1)continue;
        q.push({nn.cost+tp.first,nn.to});
      }
    }
    return dist[end];
  }
  int getd(int end){
    return dist[end];
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;cin>>k;
  dijkstra dj(k),dj2(k);
  rep(i,k)
  {
    dj.ae(i,(i+1)%k,1);
    dj2.ae((i+1)%k,i,1);

    dj.ae(i,i*10%k,0);
    dj2.ae(i*10%k,i,0);

  }
  int res=1e9;

  dj.cal(0);
  dj2.cal(0);
  rep(i,k-1)
  {
    chmin(res,dj.getd(i+1)+dj2.getd(i+1));
  }
  cout<<res<<endl;


  return 0;

}
