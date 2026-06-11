#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vll = vector<vector<ll> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;
using lthe = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int main()
{
	int h, w;
	cin >> h >> w;
	Vs G(h);
	queue<the> Q;

	int bcnt = 0;
	//初期値
	rep(i, h)  cin >> G[i];
	rep(i, h) {
		rep(j, w) {
			if (G[i][j] == '#') {
				Q.push({ i,j });
				bcnt++;
			}
		}
	}

	int ans = 0;
	int cnt = 0;
	int nbcnt = 0;
	while (!Q.empty()) {
		the v = Q.front();
		Q.pop();
		cnt++;
		//cout << cnt << " " << bcnt << " " << nbcnt << endl;
		for (int i = 0; i < 4; i++) {
			the nv = { v.first + dx[i],v.second + dy[i] };
			if (nv.first < 0 || nv.first >= h || nv.second < 0 || nv.second >= w) continue;
			if (G[nv.first][nv.second] == '#') continue;
			Q.push(nv);
			G[nv.first][nv.second] = '#';
			nbcnt++;
		}
		if (bcnt == cnt) {
			ans++;
			cnt = 0;
			bcnt = nbcnt;
			nbcnt = 0;
		}
	}
	ans--;
	cout << ans << endl;
}
