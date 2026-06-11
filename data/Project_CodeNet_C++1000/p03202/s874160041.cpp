#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2e5+5;
int n, a[MX];
stack<ii> rn;
stack<int> val;

void insert (int a, int b, int x) {
	if (a > b) return;

	while (rn.size() && rn.top().fi >= a) {
		rn.pop();
		val.pop();
	}

	if (rn.size() && rn.top().se >= a) {
		int t = rn.top().fi;
		rn.pop();
		rn.emplace(t, a - 1);
	}

	int ant = a;
	while (val.size() && val.top() == x) {
		ant = rn.top().fi;
		val.pop();
		rn.pop();
	}

	val.push(x);
	rn.emplace(ant, b);
}

bool esPos (int m) {
	while (rn.size()) rn.pop();
	while (val.size()) val.pop();

	rn.emplace(0, a[0]);
	val.push(1);

	for (int i = 1; i < n; i++) {
		if (a[i] > a[i-1]) {
			insert(a[i-1] + 1, a[i], 1);
		} else {
			while (rn.top().fi > a[i]) {
				rn.pop();
				val.pop();
			}

			if (rn.top().se > a[i]) {
				int t = rn.top().fi;
				rn.pop();
				rn.emplace(t, a[i]);
			}

			if (val.top() < m) {
				insert(a[i], a[i], val.top() + 1);
			} else {
				rn.pop();
				val.pop();

				if (rn.empty()) return 0;

				insert(rn.top().se, rn.top().se, val.top() + 1);
				insert(rn.top().se + 1, a[i], 1);
			}
		}
	}
	
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int i = 1, j = n, rep = 18;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;

	return 0;
}
