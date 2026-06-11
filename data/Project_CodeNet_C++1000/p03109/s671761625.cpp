#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ll long long

int check(ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h, ll i, ll j) {
	if(a < e && b < f && c < g && d < h) {
		return j;
	} else if(e < a && f < b && g < c && h < d) {
		return i;
	} else {
		return 1001;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int y, m, d;
	char x;
	cin >> y >> x >> m >> x >> d;
	if(m <= 4) {
		cout << "Heisei";
	} else {
		cout << "TBD";
	}
}
