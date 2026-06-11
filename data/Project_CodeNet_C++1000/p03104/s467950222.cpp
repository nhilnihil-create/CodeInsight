#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
ll cal(ll a) {
	if (a % 4 == 0)return a;
	if (a % 4 == 1)return 1;
	if (a % 4 == 2)return a + 1;
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	ll a, b;
	cin >> a >> b;
	ll ans = cal(b)^cal(a - 1) ;
	cout << ans << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}