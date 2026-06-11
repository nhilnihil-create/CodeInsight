#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

std::string substrBack(std::string str, size_t pos, size_t len) {
	const size_t strLen = str.length();

	return str.substr(strLen - pos, len);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> sl(m);
	vector<int> pl(m);
	rep(i, m) {
		int k;
		cin >> k;
		rep(j, k) {
			int s;
			cin >> s;
			sl[i].push_back(s);
		}
	}
	rep(i, m) {
		int p;
		cin >> p;
		pl[i] = p;
	}
	int ans = 0;
	int c = pow(2, n);
	rep(i, c) {
		bool isOK = true;
		rep(k, m) {
			int count = 0;
			int p = pl[k];
			rep(j, n) {
				if ((i >> j) & 1) {
					rep(l, sl[k].size()) {
						if (j == (sl[k][l] - 1)) {
							count++;
						}
					}
				}
			}
			if (count % 2 != p) {
				isOK = false;
			}
		}
		if (isOK) ++ans;
	}
	cout << ans << endl;
	system("pause");
}


