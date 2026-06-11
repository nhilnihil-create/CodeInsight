/* it was worth becoming a chemist */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uni;
typedef unsigned long long unll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const db EPS = (db) 1e-9;
const db pi = acos(-1.0);
const int MAXN = 1e5 + 5;

int n, a[MAXN];

bool check(int l, int r) {
	for (int i = l; i < r; i++) {
		if (a[i] != a[i + 1]) return 0; 
	}
	return 1;
}

int main() {	
    
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int res = 0, j = 1;
	for (int i = 1; i <= n; i++) {
		while (check(i, j)) j++;
		res += ((j - i) >> 1);
		i = j - 1;
	}
	cout << res;
	return 0;
}
