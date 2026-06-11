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
	int n;
	cin >> n;
	map<char, ll> mp;
	rep(i, n) {
		string s;
		cin >> s;
		char ss = s[0];
		if (ss == 'M'
			|| ss == 'A'
			|| ss == 'R'
			|| ss == 'C'
			|| ss == 'H'
			)
		{
			mp[ss]++;
		}
	}
	ll ans = 0;
	string sr = "MARCH";
	repi(i, 0, 5) {
		repi(j, i + 1, 5) {
			repi(k, j + 1, 5) {
				ans += mp[sr[i]] * mp[sr[j]] * mp[sr[k]];
			}
		}
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

