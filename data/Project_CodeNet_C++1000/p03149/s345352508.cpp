#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <numeric>
#include <bitset>
#include <cassert>
#include <functional>

using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll, ll> P;
inline ll min(ll x, ll y) { return x < y ? x : y; }
inline ll max(ll x, ll y) { return x > y ? x : y; }

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)

int main() {
	vector<int> N(4);
	vector<bool> b(4, false);
	rep(i, 4) {
		cin >> N[i];
		if (N[i] == 1) {
			b[0] = true;
		}
		if (N[i] == 9) {
			b[1] = true;
		}
		if (N[i] == 7) {
			b[2] = true;
		}
		if (N[i] == 4) {
			b[3] = true;
		}
	}
	rep(i, 4) {
		if (b[i] == false) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}