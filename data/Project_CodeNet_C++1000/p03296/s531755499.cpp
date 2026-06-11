#include <bits/stdc++.h>
 
#define jyldam ios_base::sync_with_stdio;cin.tie(NULL);cout.tie(NULL);

#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define sz size()
#define fi first
#define se second
 
#define cmp_all(x) (x).begin(), (x).end(), cmp
#define batr ONLINE_JUDGE
#define all(x) (x).begin(),(x).end()
#define skip continue
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = 1e6 + 17, maxN = 4 * N, darr = 1e3 + 17, mod = 1e9 + 7;

int n;
int a[N];
int q;
int ct;
 
int main () {
	jyldam;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int res = 0;
	vector <int> v;

	for (int i = 1; i <= n + 1; i++) {
		if (a[i] == a[i-1]) {
			ct++;
		}
		else {
			v.pb(ct);
			ct = 1;
		}
	}
	for (int i = 0; i < v.sz; i++) {
		res += v[i] / 2;
	}
	cout << res;
	return 0;
}