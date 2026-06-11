#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;

int h, w;
char grid[1001][1001];
vector<queue<pair<int, int> > > que(2);

bool is_range(int x, int y){
	if (1 <= x && x <= h && 1 <= y && y <= w) return true;
	return false;
}

void bfs(int x){
	int dirx[4] = {1, 0, -1, 0};
	int diry[4] = {0, 1, 0, -1};
	while(!que[x].empty()){
		auto f = que[x].front();
		que[x].pop();
		for (int i = 0; i < 4; i++){
			int nextx = f.first + dirx[i], nexty = f.second + diry[i];
			if (is_range(nextx, nexty)){
				if (grid[nextx][nexty] == '.'){
					grid[nextx][nexty] = '#';
					que[(x+1)%2].push(make_pair(nextx, nexty));
				}
			}
		}
	}
	return;
}

int main(){
	cin >> h >> w;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			cin >> grid[i][j];
			if (grid[i][j] == '#'){
				que[0].push(make_pair(i, j));
			}
		}
	}

	int ans = 0;
	for (int i = 0; ; i++){
		if (!que[i%2].empty()) bfs(i%2);
		else break;
		ans++;
	}
	
	cout << ans-1 << endl;
	return 0;
}