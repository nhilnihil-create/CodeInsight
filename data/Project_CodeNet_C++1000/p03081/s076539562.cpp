#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define se second
#define pll pair<ll, ll>
#define pii pair<int, int>
 
 
using namespace std;
 
const int N = 2e5 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int M = 210;


ll n, q;
char a[N], s[N], d[N];


bool checkleft(ll x) {
	ll curpos = x;
	for (int i = 1; i <= q; i++) {
		if (curpos == 0 || curpos == n + 1)
			break;
		if (a[curpos] == s[i]) {
			if (d[i] == 'L')
				curpos--;
			else
				curpos++;
		}		
	}
	return (curpos == 0);
}


bool checkright(ll x) {
	ll curpos = x;
	for (int i = 1; i <= q; i++) {
		if (curpos == 0 || curpos == n + 1)
			break;
		if (a[curpos] == s[i]) {
			if (d[i] == 'L')
				curpos--;
			else
				curpos++;
		}		
	}
	return (curpos == n + 1);
}


int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= q; i++)
		cin >> s[i] >> d[i];
	ll L = 1, R = n, M, a1 = 0, a2 = n + 1;
	while (L <= R) {
		M = (L + R) / 2;
		if (checkleft(M)) {
			a1 = max(a1, M);
			L = M + 1;
		} else {
			R = M - 1;
		}
	}
	L = 1; R = n;
	while (L <= R) {
		M = (L + R) / 2;
		if (checkright(M)) {
			a2 = min(a2, M);
			R = M - 1;
		} else {
			L = M + 1;
		}
	}
	a2 = n - a2 + 1;
	cout << n - a1 - a2;
	return 0;
}