#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;

struct Point {
	ll x, y;
	Point(){}
	Point(ll x, ll y):x(x), y(y){}
};
int main() {
	ll h, w;
	cin >> h >> w;
	queue<Point> blacks;
	vector<vector<ll>> distance;
	distance.resize(h);
	for (ll i = 0; i < h; i++) {
		string s;
		cin >> s;
		distance[i].resize(w);
		for (ll j = 0; j < w; j++) {
			if (s[j] == '#') {
				blacks.push(Point(i, j));
				distance[i][j] = 0;
			}
			else {
				distance[i][j] = -1;
			}
		}
	}
	ll ans = 0;
	while (!blacks.empty()) {
		Point now = blacks.front();
		blacks.pop();
		ll x = now.x;
		ll y = now.y;
		ll nowDis = distance[x][y];
		if (ans < nowDis) {
			ans = nowDis;
		}

		Point tmp[4];
		for (ll i = 0; i < 4; i++) {
			tmp[i] = now;
		}
		tmp[0].x++;
		tmp[1].x--;
		tmp[2].y++;
		tmp[3].y--;
		for (ll i = 0; i < 4; i++) {
			Point& nowtmp = tmp[i];
			if (0 <= nowtmp.x && nowtmp.x < h && 0 <= nowtmp.y && nowtmp.y < w && distance[nowtmp.x][nowtmp.y] == -1) {
				distance[nowtmp.x][nowtmp.y] = nowDis + 1;
				
				blacks.push(nowtmp);
			}
		}
	}
	/*for (ll i = 0; i < h; i++) {
		for (ll j = 0; j < w; j++) {
			cout << distance[i][j];
		}
		cout << endl;
	}*/
	cout << ans << endl;
	
}
