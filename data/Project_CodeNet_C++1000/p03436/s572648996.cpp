#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

ll H, W, dots = 0; 
vector<vector<char>> maze;
vector<ll> dy = {0, 1, 0, -1};
vector<ll> dx = {1, 0, -1, 0};
 
ll bfs(pair<ll, ll> start, pair<ll, ll> goal)
{
	vector<vector<ll>> dist(H + 2, vector<ll>(W + 2, -1));
  	queue<pair<ll, ll>> Q;
  	dist[start.first][start.second] = 0;
  	Q.push(start);
  
  	while(!Q.empty()) {
    	pair<ll, ll> v = Q.front(); Q.pop();
      	rep(i, 0, 4) {
        	pair<ll, ll> nv = make_pair(v.first + dx[i], v.second + dy[i]);
          	if (dist[nv.first][nv.second] != -1 || maze[nv.first][nv.second] == '#') {
            	continue;
            }
          	dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
          	Q.push(nv);
        }
    }
  	return dist[goal.first][goal.second];
}

int main()
{
  cin >> H >> W;
  maze = vector<vector<char>>(H + 2, vector<char>(W + 2));
  rep(j, 0, W + 2) {
  	maze[0][j] = '#';
  }
  rep(i, 1, H + 1) {
  	maze[i][0] = '#';
    rep(j, 1, W + 1) {
    	cin >> maze[i][j];
      	if (maze[i][j] == '.') dots++;
    }
    maze[i][W + 1] = '#';
  }
  rep(j, 0, W + 2) {
  	maze[H + 1][j] = '#';
  }
  ll d = bfs(make_pair(1, 1), make_pair(H, W));
  if (d == -1) cout << -1 << endl;
  else cout << dots - d - 1 << endl;
}