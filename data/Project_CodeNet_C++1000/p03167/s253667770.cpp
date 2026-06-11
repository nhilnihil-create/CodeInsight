#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int MAXH = 1010, MAXW = 1010;

char grid[MAXH][MAXW];
int dp[MAXH][MAXW];
bool visited[MAXH][MAXW];

int h, w;

ll solve(int x, int y){
	if(x >= h || y >= w) return 0;
	if(grid[x][y] == '#') return 0;
	if(visited[x][y]) return dp[x][y];
	if(x == h-1 && y == w - 1) return dp[x][y] = 1;
	
	visited[x][y] = true;
	return dp[x][y] = (solve(x+1,y) + solve(x,y+1))%MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++)
			cin >> grid[i][j];
	}
	ll ans = solve(0,0);
	cout << ans;
	
	return 0;
}
