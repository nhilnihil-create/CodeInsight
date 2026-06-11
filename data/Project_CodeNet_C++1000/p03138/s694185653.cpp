#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, k; cin >> n >> k;
	vector<ll> V(n);
	for (int i = 0; i < n; i++) cin >> V[i];
	int bs = 42;
	vector<ll> bc(bs);
	for (int i = 0; i < n; i++) {
		for (int b = 0; b < bs; b++) {
			bc[b] += (V[i] >> b) & 1;
		}
	}

	ll lmt = 0;
	ll fre = 0;
	for (int b = 0; b < bs; b++) {
		if ((k >> b) & 1) lmt = max((bc[b] << b) + fre, ((n - bc[b]) << b) + lmt);
		else  lmt += bc[b] << b;
		fre += max(bc[b], n - bc[b]) << b;
	}
	cout << lmt << endl;

	return 0;
}