#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll N, H; cin >> N >> H;
	vector<ll> a(N),b(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll cnt = 0, dmg = 0;
	for (int i = N - 1; i >= 0&&dmg<H; i--) {
		if (b[i] >= a[N - 1])cnt++, dmg += b[i];
		else break;
	}
	if (dmg < H) cnt += (H - dmg + a[N - 1] - 1) / a[N - 1];
	cout << cnt << endl;
}
