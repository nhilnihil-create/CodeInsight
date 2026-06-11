// Ala be zekrellah tatmaenolgholoob ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 1e5+9;
const ll mod = 1e9+7;

map <pair<string,string>,int> mp;

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < (1 << n); i++) {
		string cur1, cur2;
		for (int t = 0; t < n; t++)
			if (i & (1 << t))
				cur1 += s[t];
			else
				cur2 += s[t];
		mp[MP(cur1, cur2)]++;
	}
	ll res = 0;
	for (int i = 0; i < (1 << n); i++) {
		string cur1, cur2;
		for (int t = 0; t < n; t++)
			if (i & (1 << t))
				cur1 += s[2 * n - t - 1];
			else
				cur2 += s[2 * n - t - 1];
		res += mp[MP(cur1, cur2)];
	}
	cout << res << "\n";
}

