
#include<bits/stdc++.h>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 100010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }




void solve(void)
{
  int H,W;
  cin>>H>>W;
  vector<vector<char> > MAZE(H,vector<char>(W));
  pair<int,int> START,GOAL;
  int cnt_w = 0;
  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      cin>>MAZE[h][w];
      if(MAZE[h][w] == 'S')
      {
        START.first = h;START.second=w;
        MAZE[h][w] = '.';
      }

      if(MAZE[h][w] == 'G')
      {
        GOAL.first = h;GOAL.second=w;
        MAZE[h][w] = '.';  
      }
      if(MAZE[h][w] =='.')cnt_w++;      
    }
  }
  START = make_pair(0,0);
  GOAL = make_pair(H-1,W-1);
  vector<int> dx = {1,0,-1,0};
  vector<int> dy = {0,1,0,-1};
  vector<vector<int> > dist(H,vector<int>(W,INF));

  queue<pair<int,int> > q;
  q.push(START);
  dist[START.first][START.second] = 0;
  while(! q.empty())
  {
    pair<int,int> point = q.front();
    q.pop();
    if(point == GOAL) break;

    for (int i = 0; i < 4; i++)
    {
      int nx = point.second + dx[i];
      int ny = point.first + dy[i];
      if(nx >= 0 && ny >= 0 && nx < W && ny <H && MAZE[ny][nx] != '#' &&dist[ny][nx] == INF)
      {
        q.push(pair<int,int>(ny,nx));
        dist[ny][nx] = dist[point.first][point.second] + 1;
      }
    }
  }
    
  int C = dist[GOAL.first][GOAL.second];
  if(C >= INF)
  {
    cout<<-1<<endl;
    return;
  }
  C++;
  cout<<cnt_w - C<<endl;
  return;
}
int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
