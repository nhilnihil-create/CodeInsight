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
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	vector<int>v(5);
	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		v[x]++;
	}
	bool ok = false;
	for (int i = 0; i < 5; i++) {
		if (v[i] >= 3) {
			ok = true;
			break;
		}
	}
	if (ok)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}