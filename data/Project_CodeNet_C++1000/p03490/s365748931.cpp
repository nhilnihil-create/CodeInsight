#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;
struct edge { ll from; ll to; ll cost; };


int main() {
	string s;
	int x, y;
	cin >> s;
	int n = s.size();
	cin >> x >> y;

	vector<int>X;
	vector<int>Y;
	int temp = 0;
	bool fl = 0;
	rep(i, 0, s.size()) {
		if (s[i] == 'T') {
			if (!fl) {
				X.push_back(temp);
			}
			else {
				Y.push_back(temp);
			}
			temp = 0;
			if (fl)fl = 0;
			else fl = 1;
		}
		else if (i == s.size() - 1) {
			temp++;
			if (!fl) {
				X.push_back(temp);
			}
			else {
				Y.push_back(temp);
			}
		}
		else {
			temp++;
		}
	}

	if (Y.size() != 0) {
		vector< vector<int> >x_ok(X.size(), vector<int>(16200, 0));
		x_ok[0][8100 + X[0]]++;

		rep(i, 1, X.size()) {
			rep(j, 0, 16200) {
				if (x_ok[i - 1][j] > 0) {
					x_ok[i][j + X[i]]++;
					x_ok[i][j - X[i]]++;
				}
			}
		}




		vector< vector<int> >y_ok(Y.size(), vector<int>(16200, 0));
		y_ok[0][8100 + Y[0]]++;
		y_ok[0][8100 - Y[0]]++;

		rep(i, 1, Y.size()) {
			rep(j, 0, 16200) {
				if (y_ok[i - 1][j] > 0) {
					y_ok[i][j + Y[i]]++;
					y_ok[i][j - Y[i]]++;
				}
			}
		}

		if (x_ok[X.size() - 1][x + 8100] > 0 && y_ok[Y.size() - 1][y + 8100] > 0)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		if (y == 0 && x == X[0]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}


	return 0;
}