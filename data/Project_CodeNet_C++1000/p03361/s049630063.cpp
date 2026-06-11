#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector<vector<char>> grid(h+2, vector<char>(w+2, '.'));
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			cin >> grid[i][j];
		}
	}
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			if(grid[i][j] == '.') continue;
			bool ok = false;
			rep(k,4){
				if(grid[i+dy[k]][j+dx[k]] == '#') ok = true;
			}
			if(!ok){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
