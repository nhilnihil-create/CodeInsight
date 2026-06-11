#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string, string> pss;

ll n, ans;
string s;
map<pss, int> cnt;

int main() {
	cin >> n >> s;
	for (int i = 0; i < (1 << n); i++) {
		string a = "", b = "";
		for (int j = 0; j < n; j++)
			if(i & (1 << j))
				a.push_back(s[j]);
			else
				b.push_back(s[j]);
		reverse(b.begin(), b.end());
		cnt[pss(a, b)]++;
	}
	
	for (int i = 0; i < (1 << n); i++) {
		string a = "", b = "";
		for (int j = 0; j < n; j++)
			if(i & (1 << j))
				a.push_back(s[n + j]);
			else
				b.push_back(s[n + j]);
		reverse(b.begin(), b.end());
		ans += cnt[pss(b, a)];
	}
	cout << ans;
	return 0;
}