//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

ll n, ans;
string s, p1, p2;
map<pair<string, string>, ll> mp;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> s;
	p1 = s.substr(0, n);
	p2 = s.substr(n, n);
	for (int i = 0; i < (1 << n); i++) {
		string red, blue, mask;
		int t = i;
		while (t) {
			if (t & 1)
				mask += '1';
			else
				mask += '0';
			t /= 2;
		}
		while (mask.size() < n)
			mask += '0';
		for (int j = 0; j < n; j++)
			if (mask[j] == '0')
				red += p1[j];
			else
				blue += p1[j];
		mp[make_pair(red, blue)]++;
	}
	for (int i = 0; i < (1 << n); i++) {
		string red, blue, mask;
		int t = i;
		while (t) {
			if (t & 1)
				mask += '1';
			else
				mask += '0';
			t /= 2;
		}
		while (mask.size() < n)
			mask += '0';
		for (int j = 0; j < n; j++)
			if (mask[j] == '0')
				red += p2[j];
			else
				blue += p2[j];
		reverse(red.begin(), red.end());
		reverse(blue.begin(), blue.end());
		ans += mp[make_pair(blue, red)];
	}
	cout << ans << endl;
	return 0;
}
