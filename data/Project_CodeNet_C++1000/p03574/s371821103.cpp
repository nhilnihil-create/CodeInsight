#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

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
			if(grid[i][j] == '#'){
				cout << "#";
				continue;
			}
			int cnt = 0;
			rep(k,8){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(grid[ny][nx] == '#') ++cnt;
			}
			cout << cnt;
		}
		cout << endl;
	}
	return 0;
}