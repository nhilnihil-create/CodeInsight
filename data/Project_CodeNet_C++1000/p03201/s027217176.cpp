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

const int N = 2e5 + 123;
int n, a[N], ans;
map <int, int> cnt;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[-a[i]]++;
	}
	for (auto i : cnt) {
		int val = i.F;
		while (cnt[val] > 0) {
			cnt[val]--;
			for (int j = 0; j <= 30; j++) {
				int need = -((1 << j) - (-val));
				if (cnt.count(need) && cnt[need] > 0) {
					//cout << -need << ' ' << -val << '\n';
					cnt[need]--;
					ans++;
				}
			}
		}
	}
	cout << ans;
}
