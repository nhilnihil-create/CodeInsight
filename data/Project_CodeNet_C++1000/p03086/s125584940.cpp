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

int main()
{
	string s;
	cin >> s;

	vector<char> c = { 'A','C', 'G', 'T' };
	int ans = 0;
	int tmp = 0;
	rep(i, s.size()) {
		bool isOK = false;
		rep(j, c.size()) {
			if (s[i] == c[j]) {
				isOK = true;
				break;
			}
		}
		if (isOK) {
			++tmp;
		}
		else{
			tmp = 0;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	system("pause");
}


