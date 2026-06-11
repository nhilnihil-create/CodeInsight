#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

ll GCD(ll a, ll b)
{
	if (a%b == 0)
	{
		return(b);
	}
	else
	{
		return(GCD(b, a%b));
	}
}


int main() {
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> L(n);
	vector<int> R(n + 1);
	FOR(i, 1, n) {
		cin >> a[i];
	}
	L[1] = a[1];
	FOR(i, 2, n - 1) {
		L[i] = GCD(L[i - 1], a[i]);
	}
	R[n] = a[n];
	RFOR(i, n-1, 2) {
		R[i] = GCD(R[i + 1], a[i]);
	}
	int res = max(L[n - 1], R[2]);
	FOR(i, 2, n - 1) {
		int tmp = GCD(L[i - 1], R[i + 1]);
		res = max(res, tmp);
	}
	pv(res)
	return 0;
}