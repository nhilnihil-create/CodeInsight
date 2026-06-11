#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
struct edge{
    ll p;//点
    ll w;//辺の重み*-1
};
vector<vector<edge> > graph(100000);
vector<ll> dis(100000);
ll v,e,r;//vは頂点,eは辺,rは始点
void dijkstra(){
  for(int i = 0;i < v;i++)dis[i] = pow(10,18);
    dis[r] = 0;
    priority_queue<pair<ll,ll> > que;//重み、頂点
    que.push(make_pair(0,r));
    while(!que.empty()){
        edge now;
        now.p = que.top().second;
        now.w = que.top().first * -1;
        que.pop();
        if(dis[now.p] < now.w)continue;
        for(int i = 0;i < (int)graph[now.p].size();i++){
            if(dis[graph[now.p][i].p] > now.w + graph[now.p][i].w){
                dis[graph[now.p][i].p] = now.w + graph[now.p][i].w;
                que.push(make_pair(dis[graph[now.p][i].p] * -1,graph[now.p][i].p));
            }
        }
    }
}
int main(){
  ll h,w;
  cin >> h >> w;
  v = 10;
  e = 100;
  vector<ll> cost(10);
  for(int i = 0;i < 10;i++){
    for(int j = 0;j < 10;j++){
      ll in;
      cin >> in;
      edge memoa = {j,in};
      graph[i].push_back(memoa);
    }
  }
  for(int i = 0;i < 10;i++){
    r = i;
    dijkstra();
    cost[i] = dis[1];
  }
  
  ll res = 0;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      ll num = 0;
      cin >> num;
      if(num == -1)continue;
      res += cost[num];
    }
  }
  cout << res << endl;
}