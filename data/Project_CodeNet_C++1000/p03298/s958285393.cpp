#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define se second
#define int long long
#define pll pair<ll, ll>
#define pii pair<int, int>


using namespace std;

const int N = 2e5 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int p = 1e9 + 7;


int n, pw[50];
string s;
unordered_map<int, int> mp;


int hashh(string t) {
	int ans = 0;
	for (int i = 0; i < t.size(); i++) {
		int t1 = i + 1, t2 = t[i] - 'a';
		ans += t2 * pw[t1];
	}
	return ans;
}


void precalc() {
	pw[0] = 1;
	for (int i = 1; i <= 40; i++)
		pw[i] = pw[i - 1] * p;
}


main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);	
	precalc();
	cin >> n;
	cin >> s;
	string s1, s2, s3, s4;
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		s3 = ""; s4 = "";
		for (int j = 0; j < n; j++)
			if (1 & (mask>>j))
				s3 += s[j + n];
		for (int j = n - 1; j >= 0; j--)
			if (!(1 & (mask>>j)))
				s4 += s[j + n];
		int val = hashh(s4 + "#" + s3);
		if (mp.count(val))
			mp[val]++;
		else
			mp[val] = 1;
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		s1 = ""; s2 = "";
		for (int j = 0; j < n; j++)
			if (1 & (mask>>j))
				s1 += s[j];
		for (int j = n - 1; j >= 0; j--)
			if (!(1 & (mask>>j)))
				s2 += s[j];
		int val = hashh(s1 + "#" + s2);
		if (mp.count(val)) {
//			cout << s1 << " " << s2 << " " << mp[val] << endl;
			ans += mp[val];
		}
	}
	cout << ans;
	return 0;
}
