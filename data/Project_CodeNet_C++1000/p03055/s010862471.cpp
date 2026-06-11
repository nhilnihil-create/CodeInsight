/*
        _            _                  _            _       _     _         _   _          _          _             _        
       / /\         / /\               / /\         / /\    / /\  /\ \      /\_\/\_\ _     /\ \       /\ \     _    /\ \      
      / /  \       / /  \             / /  \       / / /   / / /  \ \ \    / / / / //\_\   \ \ \     /  \ \   /\_\ /  \ \     
     / / /\ \__   / / /\ \           / / /\ \__   / /_/   / / /   /\ \_\  /\ \/ \ \/ / /   /\ \_\   / /\ \ \_/ / // /\ \_\    
    / / /\ \___\ / / /\ \ \         / / /\ \___\ / /\ \__/ / /   / /\/_/ /  \____\__/ /   / /\/_/  / / /\ \___/ // / /\/_/    
    \ \ \ \/___// / /  \ \ \        \ \ \ \/___// /\ \___\/ /   / / /   / /\/________/   / / /    / / /  \/____// / / ______  
     \ \ \     / / /___/ /\ \        \ \ \     / / /\/___/ /   / / /   / / /\/_// / /   / / /    / / /    / / // / / /\_____\ 
 _    \ \ \   / / /_____/ /\ \   _    \ \ \   / / /   / / /   / / /   / / /    / / /   / / /    / / /    / / // / /  \/____ / 
/_/\__/ / /  / /_________/\ \ \ /_/\__/ / /  / / /   / / /___/ / /__ / / /    / / /___/ / /__  / / /    / / // / /_____/ / /  
\ \/___/ /  / / /_       __\ \_\\ \/___/ /  / / /   / / //\__\/_/___\\/_/    / / //\__\/_/___\/ / /    / / // / /______\/ /   
 \_____\/   \_\___\     /____/_/ \_____\/   \/_/    \/_/ \/_________/        \/_/ \/_________/\/_/     \/_/ \/___________/    
                                                                                                                              
*/
#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for(int i = 0;i < (n);++i)

// #define endl '\n'
#define pb emplace_back
#define mkp make_pair
#define p_q priority_queue
#define INF 1000000000
#define PI 3.1415926
#define coutdb cout << fixed << setprecision(10)

const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};
const int dx_8[]={1,1,0,-1,-1,-1,0,1}, dy_8[]={0,-1,-1,-1,0,1,1,1};
const long long MOD = 1e9+7;

typedef long long ll;
// #define int long long

template <typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}

typedef pair<int, int> P;
vector<int> graph[200000];
int N;

P dfs(int s){
  vector<int> dist(N, INF);
  dist[s] = 0;
  queue<int> que; que.push(s);

  while(!que.empty()){
    int now = que.front(); que.pop();
    REP(i, (int)graph[now].size()){
      int next = graph[now][i];
      if(dist[next] == INF){
        dist[next] = dist[now]+1;
        que.push(next);
      }
    }
  }

  int mx = -1, mxindex;
  REP(i, N){
    if(dist[i] > mx) {
      mx = dist[i];
      mxindex = i;
    }
  }

  return P(mxindex, mx);
}

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N-1){
    int a, b; cin >> a >> b;
    a--; b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  P tmp = dfs(0);
  tmp = dfs(tmp.first);
  int L = tmp.second;

  cerr << L << endl;

  if(L % 3 == 1) cout << "Second" << endl;
  else cout << "First" << endl;

  return 0;
}