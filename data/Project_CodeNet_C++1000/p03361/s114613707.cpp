#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}

ll box(double a)
{
	ll b = a;
	return b;
}

ll fff(double a)
{
	ll b = a + 0.5;
	return b;
}

int main() {
	ll n, m;
	cin >> n >> m;
	vcc data(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> data[i][j];
		}
	}
	bool ans = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != 0 && i != n - 1 && j != 0 && j != m - 1) {
				if (data[i][j] == '#') {
					if (data[i + 1][j] == '.' && data[i - 1][j] == '.' && data[i][j + 1] == '.' && data[i][j - 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (i == 0 && j == 0) {
				if (data[i][j] == '#') {
					if (data[i + 1][j] == '.' && data[i][j + 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (i == 0 && j == m - 1) {
				if (data[i][j] == '#') {
					if (data[i + 1][j] == '.' && data[i][j - 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (i == n - 1 && j == 0) {
				if (data[i][j] == '#') {
					if (data[i - 1][j] == '.' && data[i][j + 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (i == n - 1 && j == m - 1) {
				if (data[i][j] == '#') {
					if (data[i - 1][j] == '.' && data[i][j - 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (i == n - 1 && j != m - 1 && j != 0) {
				if (data[i][j] == '#') {
					if (data[i - 1][j] == '.' && data[i][j - 1] == '.' && data[i][j + 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (i == 0 && j != 0 && j != m - 1) {
				if (data[i][j] == '#') {
					if (data[i][j + 1] == '.' && data[i][j - 1] == '.' && data[i + 1][j] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (j == 0 && i != n - 1 && i != 0) {
				if (data[i][j] == '#') {
					if (data[i + 1][j] == '.' && data[i - 1][j] == '.' && data[i][j + 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
			if (j == m - 1 && i != 0 && i != n - 1) {
				if (data[i][j] == '#') {
					if (data[i + 1][j] == '.' && data[i - 1][j] == '.' && data[i][j - 1] == '.') {
						ans = false;
                      break;
					}
				}
			}
		}
	}
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
        cout << "No" << endl;
    }
}