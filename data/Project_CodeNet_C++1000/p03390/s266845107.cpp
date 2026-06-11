#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int q, a, b;
signed main() {
	cin >> q;
	rep(i, q) {
		cin >> a >> b;
		int mi = min(a, b), ma = max(a, b) + 1;
		while (mi + 1 < ma) {
			int md = (mi + ma) / 2;
			if (md * md < a * b)mi = md;
			else ma = md;
		}
		int c = mi;
		if (a == b || abs(a - b) == 1)cout << min(a, b) * 2 - 2 << endl;
		else if (c * (c + 1) >= a * b)cout << c * 2 - 2 << endl;
		else cout << c * 2 - 1 << endl;
	}
}