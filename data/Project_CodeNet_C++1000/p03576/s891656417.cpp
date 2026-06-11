#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,K;
	cin >> n >> K;
	vector<int> x(n);
	vector<int> y(n);
	vector<P> xy(n);

	for(int i = 0;i < n;i++){
		int xx,yy;
		cin >> xx >> yy;
		x[i] = xx;
		y[i] = yy;
		xy[i] = P(xx,yy);
	}

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	map<int,int> zx;
	map<int,int> zy;
	for(int i = 0;i < n;i++){
		zx[x[i]] = i+1;
		zy[y[i]] = i+1;
	}
	vector<vector<int>> grid(n+1,vector<int>(n+1,0));

	for(int i = 0;i < n;i++){
		int pos_x = zx[xy[i].first];
		int pos_y = zy[xy[i].second];
		grid[pos_y][pos_x]++;
	}

	for(int i = 1;i <= n;i++){
		for(int j = 0;j < n;j++){
			grid[i][j+1] = grid[i][j+1] + grid[i][j];
		}
	}

	for(int i = 1;i <= n;i++){
		for(int j = 0;j < n;j++){
			grid[j+1][i] = grid[j+1][i] + grid[j][i];
		}
	}

	ll ans = 5e18;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			for(int k = i+2;k <= n;k++){
				for(int l = j+2;l <= n;l++){
					int cnt = grid[k][l] - grid[i][l] - grid[k][j] + grid[i][j];
					ll dx = x[l-1] - x[j];
					ll dy = y[k-1] - y[i];
					if(cnt >= K){
						ans = min(ans,dx*dy);
					}
				}
			}
		}
	}

	cout << ans << endl;
}
