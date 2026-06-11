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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) cin >> A[i];
  queue<P> que;
  que.push(make_pair(0,0));
  vector<vector<int>> dist(H,vector<int> (W,-1));
  dist[0][0]=1;
  while(!que.empty()){
    P v = que.front();
    que.pop();
    REP(i,4){
      if(v.second+dy[i]<0||v.first+dx[i]<0||v.second+dy[i]>H-1||v.first+dx[i]>W-1||A.at(v.second+dy[i]).at(v.first+dx[i])=='#'||dist.at(v.second+dy[i]).at(v.first+dx[i])!=-1) continue;
      que.push(make_pair(v.first+dx[i],v.second+dy[i]));
      dist.at(v.second+dy[i]).at(v.first+dx[i])=dist.at(v.second).at(v.first)+1;
    }
  }

  int cnt = 0;
  REP(i,H){
    REP(j,W){
      if(A[i][j]=='#'){
        cnt++;
      }
    }
  }

  if(dist[H-1][W-1]==-1){
    cout << -1 << endl;
  }else{
    cout << H*W-dist[H-1][W-1]-cnt << endl;
  }
}