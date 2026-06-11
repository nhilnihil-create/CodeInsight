#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int inf = 1000000000;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main(){
  int h, w; cin >> h >> w;
  char a[h][w];
  int dist[h][w];
  rep(i, h)rep(j, w) dist[i][j] = inf;
  deque <P> d;
  rep(i, h)rep(j, w){
    cin >> a[i][j];
    if (a[i][j] == '#'){
      dist[i][j] = 0;
      d.emplace_back(P(i, j));
    }
  }
  while (d.size() > 0){
    int now_i = d.front().first;
    int now_j = d.front().second;
    d.pop_front();
    rep(i, 4){
      int nex_i = now_i + di[i];
      int nex_j = now_j + dj[i]; 
      if (nex_i < 0 || nex_i >= h||nex_j < 0 || nex_j >= w) continue;
      else if (a[nex_i][nex_j] ==  '#')continue;
      else{
        dist[nex_i][nex_j] = min(dist[now_i][now_j] + 1,  dist[nex_i][nex_j]);
        a[nex_i][nex_j] = '#';
        d.emplace_back(P(nex_i, nex_j));
      }
    }
  }
  int ans = 0;
  rep(i, h)rep(j, w) {
    ans = max(ans, dist[i][j]);
  }
  cout << ans << endl;
}