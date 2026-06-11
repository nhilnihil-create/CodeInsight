#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N;
  cin >> N;
  vector<P> A(N-1);
  vector<vector<int>> List(N,vector<int> ());
  REP(i,N-1){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
    List[A[i].first].push_back(A[i].second);
    List[A[i].second].push_back(A[i].first);
  }
  vector<int> B(N);
  REP(i, N) cin >> B[i];
  sort(ALL(B));
  int ans = 0;
  REP(i,N-1){
    ans+=B[i];
  }
  cout << ans << endl;
  queue<int> que;
  que.push(0);
  vector<int> dist(N,-1);
  dist[0]=0;
  reverse(ALL(B));
  int now = 0;
  vector<int> vec(N);
  vec[0]=B[0];
  now=1;
  while(!que.empty()){
    int v = que.front();
    que.pop();
    for(auto nv:List[v]){
      if(dist[nv]!=-1) continue;
      que.push(nv);
      dist[nv]=0;
      vec[nv]=B[now];
      now++;
    }
  }

  REP(i,N){
    cout << vec[i];
    if(i!=N-1){
      cout << " ";
    }
  }
  cout << endl;
}