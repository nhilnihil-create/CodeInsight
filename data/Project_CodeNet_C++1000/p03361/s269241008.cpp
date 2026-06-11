#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll H, W; cin >> H >> W;
  vector<vector<char>> grid(H + 2, vector<char>(W + 2));
  rep(j, 0, W + 2) {
  	grid[0][j] = '.';
  }
  rep(i, 1, H + 1) {
  	grid[i][0] = '.';
    rep(j, 1, W + 1) {
    	cin >> grid[i][j];
    }
    grid[i][W + 1] = '.';
  }
  rep(j, 0, W + 2) {
  	grid[H + 1][j] = '.';
  }
  rep(i, 1, H + 1) {
  	rep(j, 1, W + 1) {
    	if (grid[i][j] == '#' && grid[i - 1][j] == '.' && grid[i + 1][j] == '.' && grid[i][j - 1] == '.' && grid[i][j + 1] == '.') {
        	cout << "No"; return 0;
        }
    }
  }
  cout << "Yes";
}