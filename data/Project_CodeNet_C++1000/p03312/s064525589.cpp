#include "bits/stdc++.h"
using namespace std;
#define Would
#define you
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const double pi = acos(-1);
const int SIZE = 1 << 17;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

long long n;
int main() {
	cin >> n;
	vector<long long>k(n + 1), l(n + 1);
	for (int i = 1; i <= n; ++i) { cin >> k[i]; }
	for (int i = 1; i <= n; ++i) { l[i] = l[i - 1] + k[i]; }
	long long ans = INF;
	for (long long i = 2; i <= n - 2; ++i) {
		long long mon = lower_bound(l.begin() + 1, l.end(), l[i] / 2) - l.begin(), monn = lower_bound(l.begin() + 1, l.end(), (l[i] + l[n]) / 2) - l.begin();
		for (long long j = max((long long)0, mon - 1); j <= min(i - 1, mon + 1); ++j) {
			for (long long kk = max(i + 1, monn - 1); kk <= min(n, (long long)monn + 1); ++kk) {
				vector<long long>v = { l[j],l[i] - l[j],l[kk] - l[i],l[n] - l[kk] };
				sort(v.begin(), v.end());
				ans = min(ans, v[3] - v[0]);
			}
		}
	}
	cout << ans << endl;
}
