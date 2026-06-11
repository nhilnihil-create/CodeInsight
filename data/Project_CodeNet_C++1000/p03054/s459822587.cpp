#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 1e5+5;



int main() {
	int h, w, n;
	cin >> h >> w >> n;

	pii p;
	cin >> p.first >> p.second;
	string s, t;
	cin >> s >> t;


	vector<char> ct{ 'L','R' ,'U' ,'D' };
	vector<vector<int>> dt{ {0,-1},{0,1} ,{-1,0},{1,0} };
	vector<char> ca{ 'R','L' ,'D' ,'U' };
	vector<vector<int>> da{ {0,1},{0,-1} ,{1,0},{-1,0}};
	for (int i = 0; i < 4; i++) {
		int r = p.first;
		int c = p.second;


		for (int j = 0; j < n; j++) {


			if (s[j] == ct[i]) {
				r += dt[i][0];
				c += dt[i][1];
			}
			//cout << i << " " << r << " " << c << endl;
			if (r <1 || r >h|| c <1|| c >w) {
				cout << "NO" << endl;

				return 0;
			}
			if (t[j] == ca[i]) {
				r += da[i][0];
				c += da[i][1];
			}

			r = min(r, h);
			r = max(r, 1);
			c = min(c, w);
			c = max(c, 1);
			
			

				


			//cout <<i << " " <<  r << " " << c << endl;

		}

	}

	cout << "YES" << endl;
}