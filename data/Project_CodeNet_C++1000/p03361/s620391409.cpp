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
	int h,w;
	cin >> h >> w;
	vector<string> grid(h);
	for(int i = 0;i < h;i++)cin >> grid[i];

	vector<vector<bool>> gf(h,vector<bool>(w,false));
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(grid[i][j] == '#'){
				int dx[4] = {0,1,0,-1};
				int dy[4] = {1,0,-1,0};

				for(int k = 0;k < 4;k++){
					int nx = j + dx[k];
					int ny = i + dy[k];
					if(0 <= nx && nx < w && 0 <= ny && ny < h && grid[ny][nx] == '#'){
						gf[i][j] = true;
						gf[ny][nx] = true;
					}
				}
			}
		}
	}

	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(grid[i][j] == '#' && gf[i][j] == false){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
