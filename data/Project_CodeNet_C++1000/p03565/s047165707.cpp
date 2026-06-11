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
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int main()
{
	string s, t;
	cin >> s >> t;
	int index = -1;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	rep(i, s.size()) {
		bool isOK = true;
		rep(j, t.size()) {
			if (i + j >= s.size()) {
				isOK = false;
				break;
			}
			if (!(s[i + j] == t[j] || s[i + j] == '?')) {
				isOK = false;
				break;
			}
		}
		if (isOK) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	string ans = "";
	rep(i, s.size()) {
		if (i >= index && i < index + t.size()) {
			ans += t[i - index];
			continue;
		}
		if (s[i] == '?') {
			ans += "a";
			continue;
		}
		ans += s[i];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

