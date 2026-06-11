#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n-1;i>s;i--)
#define rep_re(i,s,n)for(ll i = n-1;i>=s;i--)
ll MOD = 1e9 + 7;

//initial : call init_uf();
//unite x and y : unite(ll x, ll y)
//same x and y : uf(x) == uf(y);
//size s[uf(a)];

static const ll MAX_N = 100001;
ll p[MAX_N] = {};//i: node ID, p[i]: root node id 
ll s[MAX_N] = {};//i: node ID, s[i]: size of group which has node i 
ll uf(ll i) { return (p[i] == i) ? i : p[i] = uf(p[i]); }
void init_uf() { rep(i, 1, MAX_N) { p[i] = i; s[i] = 1; } }
void unite(ll x, ll y) {
	x = uf(x); y = uf(y);
	if (x == y) return;
	if (p[x] > p[y]) swap(x, y); // merge technique
	s[x] += s[y];
	p[y] = x;
}


ll q[100001] = {};
bool ans[100001] = {};
ll x_id[100001] = {};
ll y_id[100001] = {};
int main() {
	init_uf();
	ll n, m; cin >> n >> m;
	repe(i, 1, n) cin >> q[i];
	rep(i, 0, m) {
		cin >> x_id[i] >> y_id[i];
		unite(q[x_id[i]], q[y_id[i]]);
	}


	ll A = 0;
	repe(i, 1, n) {
		if (uf(q[i]) == uf(i)) {
			A++;
		}
	}

	cout << A << endl;
	return 0;
}

