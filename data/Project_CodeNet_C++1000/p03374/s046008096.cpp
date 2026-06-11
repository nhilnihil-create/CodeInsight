#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define ll long long
#define pii pair < int, int >
#define fr first
#define sc second
#define mk make_pair
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define ok puts("ok");
#define whatis(x) cerr << #x << " = " << x << endl;
#define pause system("pause");
#define random rand() ^ (rand() << 5)

const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

ll ans;
ll x[N]; 
int v[N];
vector < ll > v1, v2;

main() {
	int n;
	ll c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		scanf("%lld %d", &x[i], &v[i]);
	}
	v1.resize(n + 1);
	v2.resize(n + 1);
	ll sum = 0;            
	for (int i = 1; i <= n; i++) {
		sum += v[i];
		ans = max(ans, sum - x[i]);
		v1[i] = sum - x[i];
	}
	sum = 0;
	set < pair < ll, int > > s, s1; 	
	for (int i = n; i >= 1; i--) {
		sum += v[i];
		ans = max(ans, sum - (c - x[i]));
		v2[i] = sum - (c - x[i]);
		s.insert(mk(-v2[i], i));
		s1.insert(mk(-v1[i], i));
	}
	for (int i = 1; i < n; i++) {
		s.erase(mk(-v2[i], i));
		ll cur = -s.begin() -> fr;
		ans = max(ans, v1[i] + cur - x[i]);
	}
	for (int i = n; i > 1; i--) {
		s1.erase(mk(-v1[i], i));
		ll cur = -s1.begin() -> fr;
		ans = max(ans, v2[i] + cur - (c - x[i]));
	}
	cout << ans;
}