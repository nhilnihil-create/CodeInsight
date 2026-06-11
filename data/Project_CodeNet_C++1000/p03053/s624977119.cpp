#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	ll tmp;
	ll h, w;
	cin >> h >> w;
	vector<string> mp;
	string s;
	REP(i, h) {
		cin >> s;
		mp.push_back(s);
	}
	int co[h][w];
	queue<pair<int, int>> q;
	REP(i,h) REP(j, w) {
		co[i][j] = -1;
		if(mp[i][j] == '#'){
			q.push(make_pair(i, j));
			co[i][j] = 0;
		}
	}
	int x, y;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		tmp = co[x][y];
		q.pop();
		if(x+1 < h && mp[x+1][y] == '.'){
			q.push(make_pair(x+1, y));
			mp[x+1][y] = '#';
			co[x+1][y] = tmp+1;
		}
		if(x-1 >= 0 && mp[x-1][y] == '.'){
			q.push(make_pair(x-1, y));
			mp[x-1][y] = '#';
			co[x-1][y] = tmp+1;
		}
		if(y-1 >= 0 && mp[x][y-1] == '.'){
			q.push(make_pair(x, y-1));
			mp[x][y-1] = '#';
			co[x][y-1] = tmp+1;
		}
		if(y+1 < w && mp[x][y+1] == '.'){
			q.push(make_pair(x, y+1));
			mp[x][y+1] = '#';
			co[x][y+1] = tmp+1;
		}
	}
	REP(i,h) REP(j, w) ans = max(ans, (ll)co[i][j]);
	cout << ans << endl;
}
