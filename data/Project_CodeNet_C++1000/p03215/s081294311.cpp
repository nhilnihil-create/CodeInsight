#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define puts(x) cout << x << endl
using namespace std;
int n, a[1234], k, ans;
vector<int>v;
bool b[1234 * 1234];
signed main() {
	cin >> n >> k;
	for1(i, n) {
		cin >> a[i]; a[i] += a[i - 1];
		for0(j, i)v.push_back(a[i] - a[j]);
	}
	int p = 1099511627776;
	while (p > 0) {
		int cnt = 0;
		for0(i, v.size())if ((v[i] / p) % 2 && !b[i])cnt++;
		if (cnt >= k) {
			for0(i, v.size())if ((v[i] / p) % 2 == 0)b[i] = 1;
			ans += p;
		}
		p /= 2;
	}
	puts(ans);
}