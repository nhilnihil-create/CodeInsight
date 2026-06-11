#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define rep(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int r, d;
	int x;
	cin >> r >> d >> x;
	for (int i = 0; i < 10; i++) {
		x = x * r - d;
		cout << x << endl;
	}
	return 0;
}
