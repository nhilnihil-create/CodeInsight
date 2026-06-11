#include<bits/stdc++.h> 
using namespace std; 
//python interactive_runner.py python3 local_testing_tool.py 0 -- ./Code
 
#define x first
#define y second
#define rep(i, a,b) for(int i = int(a); i < int(b); ++i)
#define forn(i,b) for(int i = 0; i < int(b); ++i)
typedef pair<int, int> pii;
int H,W;
const int MAXH = 1000+6;
char grid[MAXH][MAXH];
void solve(){
	
	cin>>H>>W;
	queue<pair<int,int> > q;
	vector<vector<int> > dis(H,vector<int> (W,0));
	vector<vector<int> > vis(H,vector<int> (W,0));
	forn(i,H){
		forn(j,W){
			cin>>grid[i][j];
			if(grid[i][j]=='#'){
				q.push({i,j});
				vis[i][j] = 1;
			} 
		}
	}
	
	int d_x[4] = {-1,1,0,0};
	int d_y[4] = {0,0,-1,1};
	pair<int,int> current;
	int maxdis = 0;
	while(!q.empty()){
		current = q.front();
		q.pop();
		forn(j,4){
			int n_x = current.x + d_x[j];
			int n_y = current.y + d_y[j];
			if(n_x>=0 && n_x<H && n_y>=0 && n_y< W && vis[n_x][n_y]==0){
				vis[n_x][n_y] = 1;
				dis[n_x][n_y] = dis[current.x][current.y]+1;
				maxdis = max(maxdis,dis[n_x][n_y]);
				q.push({n_x,n_y});
				
			}
		}
	}
	cout<<maxdis<<'\n';
}
int main(){
	solve();
	return 0;
}