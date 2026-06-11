#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

struct edge {
  ll to, cost;
};

vector<edge> graph[100010];

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> A(N-1,vector<ll>(3));
  REP(i, N-1){
    REP(j, 3){
      cin >> A.at(i).at(j);
    }
    A.at(i).at(0)--;
    A.at(i).at(1)--;
    edge e = {A.at(i).at(1),A.at(i).at(2)};
    graph[A.at(i).at(0)].push_back(e);
    edge e2 = {A.at(i).at(0),A.at(i).at(2)};
    graph[A.at(i).at(1)].push_back(e2);
  }

  vector<ll> ans(N,0);
  ans[0]=0;
  queue<ll> que;
  vector<ll> dist(N,-1);
  que.push(0);
  dist[0]=0;
  while(!que.empty()){
    ll v = que.front();
    que.pop();
    for(auto ne:graph[v]){
      ll nv = ne.to;
      if(dist[nv]!=-1) continue;
      dist[nv]=dist[v]+ne.cost;
      if(dist[nv]%2==0){
        ans[nv]=0;
      }else{
        ans[nv]=1;
      }
      que.push(nv);
    }
  }

  REP(i,N){
    cout << ans[i] << endl;
  }
}