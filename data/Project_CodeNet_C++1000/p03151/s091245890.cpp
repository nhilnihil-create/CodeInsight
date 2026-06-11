#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
//#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
int n, sum;
int a[123456], b[123456];
bool t[123456];
signed main() {
	cin >> n;
	for1(i, n) cin >> a[i];
	for1(i, n) {
		cin >> b[i];
		a[i] -= b[i];
		sum += a[i];
	}
	if (sum < 0) { cout << "-1\n"; return 0; }
	sort(a + 1, a + n + 1);
	int p = n;
	for1(i, n) {
		while (a[i] < 0) {
			t[i] = 1;
			if (abs(a[i]) < a[p]) {
				a[p] += a[i]; a[i] = 0; t[p] = 1;
			}
			else {
				a[i] += a[p]; a[p] = 0; t[p] = 1; p--;
			}
		}
	}
	int ans = 0; for1(i, n)ans += t[i];
	cout << ans << endl;
}