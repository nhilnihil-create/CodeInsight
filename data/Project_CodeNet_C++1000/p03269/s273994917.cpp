#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define se second
#define pll pair<ll, ll>
#define pii pair<int, int>
 
 
using namespace std;
 
const int N = 1e6 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int M = 210;


ll L, pw[40], mx[N], edg = 0;
vector <pll> g[M];


void rec(ll beg, ll x) {
//	cout << x << " " << mx[x] + 2 << " " << beg << "\n";
	if (x == 0) {
		g[1].pb({20, beg});
//		cout << 1 << " " << 20 << " " << beg << "\n";
		edg++;
		return;
	}
	g[mx[x] + 2].pb({20, beg});
	if (mx[x] + 2 != 20)
		edg++; 
//	cout << mx[x] + 2 << " " << 20 << " " << beg << "\n";
//	cout << pw[mx[x] + 1] - 1 << "\n";
	if (pw[mx[x] + 1] - 1 == x)
		return;
	rec(beg + pw[mx[x] + 1], x - pw[mx[x] + 1]);
}


int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
//	freopen("input.txt", "r", stdin);
//	if (L == 0) {
//		cout << "2 1\n" << "1 2 0";
//		return 0; 
//	}
	ll t = 1;
	for (ll i = 0; i <= 33; i++) {
		pw[i] = t;
		t *= 2;
	}
//	cout << pw[19] - 1 << "\n";
	cin >> L;
	L--;
	mx[0] = 0;
	mx[1] = 0;
	for (ll i = 2; i <= 1000000; i++) {
		if (pw[mx[i - 1] + 2] <= i + 1)
			mx[i] = mx[i - 1] + 1;
		else
			mx[i] = mx[i - 1];
	}
	ll brd = pw[19] - 1;
	for (int i = 1; i <= 18; i++) {
		g[i].pb({i + 1, pw[i - 1]});
		g[i].pb({i + 1, 0});
		edg+=2;
	}
	if (L >= brd) {
		g[19].pb({20, pw[18]});
		g[19].pb({20, 0});
		edg+=2;
	}
	rec(0, L);
	cout << 20 << " " << edg << "\n";
	for (int i = 1; i <= 20; i++)
		for (pll to : g[i])
			if (to.f != i)
				cout << i << " " << to.f << " " << to.se << "\n";
	return 0;
}