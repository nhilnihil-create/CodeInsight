#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define eps 1.0e-14;

queue<pair<int,int>> que;
string s[1005];
ll ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
	int h,w; cin >> h >> w;
	rep(i,h) cin >> s[i];

	vector<vector<int>> vec(h, vector<int>(w, -1));

	rep(i,h){
		rep(j,w){
			if(s[i][j] == '#'){
				que.push(make_pair(i,j));
				vec[i][j] = 0;
			}
		}
	}
	while(que.size() != 0){
		pair<int,int> nowq = que.front();
		que.pop();
		rep(i,4){
			int nowx = nowq.first + dx[i];
			int nowy = nowq.second + dy[i];
			if(nowx >= h || nowy >= w || nowx < 0 || nowy < 0) continue;
			if(vec[nowx][nowy] == -1){
				vec[nowx][nowy] = vec[nowq.first][nowq.second] + 1;
				que.push(make_pair(nowx,nowy));
			}
		}
	}
	int ans = 0;
	rep(i,h){
		rep(j,w){
			ans = max(ans,vec[i][j]);
			//cout << vec[i][j];
		}
		//cout << endl;
	}
	cout << ans;
	return 0;
}
