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

int main()
{
  int N,M;
  cin >> N >> M;
  vector<vector<int>> List(N,vector<int>());
  vector<P> A(M);
  REP(i,M){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
    List[A[i].first].push_back(A[i].second);
    List[A[i].second].push_back(A[i].first);
  }
  
  int ans = 0;
  REP(i,M){
    queue<int> que;
    que.push(0);
    vector<int> dist(N,-1);
    dist[0]=1;
    int cnt = 1;
    while(!que.empty()){
      int v = que.front();
      que.pop();
      for(auto nv:List[v]){
        if(((A[i].first==v&&A[i].second==nv)||(A[i].first==nv&&A[i].second==v))||dist[nv]!=-1){
          continue;
        }
        cnt++;
        dist[nv]=dist[v]+1;
        que.push(nv);
      }
    }
    if(cnt!=N){
      ans++;
    }
  }

  cout << ans << endl;
}