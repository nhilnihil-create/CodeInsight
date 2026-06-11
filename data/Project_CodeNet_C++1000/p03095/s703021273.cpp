#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

const int MOD = 1e9 + 7;
int n, cnt[26];
string s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	int res = 1;
	for (int i = 0; i < 26; i++) {
		res = (ll)res * (cnt[i] + 1) % MOD;
	}
	res -= 1;
	if (res < 0) {
		res += MOD;
	}
	cout << res;
}
