#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 500 + 5, C = 30 + 5, inf = 1e9;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int g[N][N], d[C][C];
	int n,c;
	cin >> n >> c;
	rep(i,1,c+1){
		rep(j,1,c+1){
			cin >> d[i][j];
		}
	}
	rep(i,1,n+1){
		rep(j,1,n+1){
			cin >> g[i][j];
		}
	}
	vector<vector<pii>> top(3);
	rep(mod,0,3){
		int best = inf;
		rep(col,1,c+1){
			int cur = 0;	
			rep(i,1,n+1){
				rep(j,1,n+1){
					if((i + j) % 3 == mod){
						if(g[i][j] != col){
							cur += d[g[i][j]][col];
						}
					}
				}
			}
			top[mod].push_back({cur, col});
		}
	}
	rep(i,0,3){
		sort(all(top[i]));	
	}
	int ans = inf;
	rep(i,0,3){
		rep(j,0,3){
			rep(k,0,3){
				if(top[0][i].second != top[1][j].second && top[1][j].second != top[2][k].second && top[0][i].second != top[2][k].second){
					gmin(ans, top[0][i].first + top[1][j].first + top[2][k].first);
				}
			}
		}
	}
	cout << ans << '\n';
}
