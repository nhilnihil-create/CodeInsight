#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n;
int izq[MX], der[MX];
ll x, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n)
		cin >> der[i] >> izq[i];

	sort(izq, izq + n);
	sort(der, der + n, greater<int>());

	int act = 0;
	forn (i, n) {
		if (izq[i] < act) {
			x += abs(act - izq[i]);
			act = izq[i];
		} else break;

		if (der[i] > act) {
			x += abs(act - der[i]);
			act = der[i];
		} else break;
	}
	x += abs(act);
	
	act = 0;
	forn (i, n) {
		if (der[i] > act) {
			y += abs(act - der[i]);
			act = der[i];
		} else break;

		if (izq[i] < act) {
			y += abs(act - izq[i]);
			act = izq[i];
		} else break;
	}
	y += abs(act);

	cout << max(x, y) << endl;

	return 0;
}
