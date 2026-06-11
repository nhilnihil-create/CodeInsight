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

const int N = 20003, M = 30000;
int n, arr[N], used[M + 3];
vector <int> two, three, six;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	for (int i = M; i >= 1; i--) {
		if (i % 6 == 0) {
			six.pb(i);
		}	else {
			if (i % 2 == 0) {
				two.pb(i);
			}
			if (i % 3 == 0) {
				three.pb(i);
			}
		}
	}
	cin >> n;
	if (n >= 5) {
		int TWO = M / 2 - M / 6;
		int THREE = M / 3 - M / 6;
		int a = -1, b = -1, c = -1;
		for (int i = 2; i <= min(TWO, n); i += 2) {
			for (int j = 2; j <= min(THREE, n - i); j += 2) {
				if (M / 6 >= n - i - j) {
					a = i, b = j, c = n - i - j;
					break;
				}
			}
		}
		int m = 0;
		while (a--) {
			arr[++m] = two.back();
			two.ppb();
		}
		while (b--) {
			arr[++m] = three.back();
			three.ppb();
		}
		while (c--) {
			arr[++m] = six.back();
			six.ppb();
		}
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << ' ';
		}
		
		//ll total = 0;
		//for (int i = 1; i <= m; i++) {
			//total += arr[i];
		//}
		//cout << '\n';
		//for (int i = 1; i <= m; i++) {
			//if (__gcd((ll)arr[i], total - arr[i]) == 1 || arr[i] > M || arr[i] < 1) {
				//cout << "WA pos " << i;
				//return 0;
			//}
		//}
		//int tmp = 0;
		//for (int i = 1; i <= m; i++) {
			//tmp = __gcd(tmp, arr[i]);
		//}
		//if (tmp != 1) {
			//cout << "WA gcd " << tmp;
			//return 0;
		//}
		//cout << "OK";
	}	else {
		if (n == 3) {
			cout << "2 5 63";
			return 0;
		}
		if (n == 4) {
			cout << "2 5 20 63";
			return 0;
		}
	}
}
