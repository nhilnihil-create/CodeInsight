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

int n, ans = 1e9;

int get(int x) {
	int res = 0;
	do {
		res += x % 10;
		x /= 10;
	}	while (x);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int j = n - i;
		ans = min(ans, get(i) + get(j));
	}
	cout << ans;
}
