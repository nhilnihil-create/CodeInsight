#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

typedef pair<string, string> ss;

int n;
string s;
ll res = 0;

map<ss, int> mp;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;

	for (int i = 0; i < (1 << n); i++) {
		string a, b;

		for (int j = 0; j < n; j++)
			if (i & (1 << j)) a.pb(s[j]);
			else b.pb(s[j]);

		mp[ss(a, b)]++;
	}

	for (int i = 0; i < (1 << n); i++) {
		string a, b;

		for (int j = 0; j < n; j++)
			if (i & (1 << j)) a.pb(s[j+n]);
			else b.pb(s[j+n]);

		reverse(ALL(a));
		reverse(ALL(b));

		res += mp[ss(a, b)];
	}

	cout << res << endl;

	return 0;
}