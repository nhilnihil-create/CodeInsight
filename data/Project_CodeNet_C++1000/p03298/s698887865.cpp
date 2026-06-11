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
		for (int j = n - 1; j >= 0; j--)
			if((i & (1 << j)) == 0)
				b.push_back(s[j]);
		cnt[pss(a, b)]++;
	}
	
	for (int i = 0; i < (1 << n); i++) {
		string a = "", b = "";
		for (int j = 0; j < n; j++)
			if(i & (1 << j))
				a.push_back(s[n + j]);
		for (int j = n - 1; j >= 0; j--)
			if((i & (1 << j)) == 0)
				b.push_back(s[j + n]);
		ans += cnt[pss(b, a)];
	}
	cout << ans;
	return 0;
}