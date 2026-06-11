#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define show(a) cerr << #a <<" -> "<< a <<"\n"
#define fo(a, b, c, d) for(int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for(int (a) = (b); (a) >= (c); (a) -= (d))
#define int ll

const int N = 2e5;
const int INF = 1e9;

int ta, ua, tp, ans;

main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> ua >> ta >> tp;
	ans += min(tp, ua);
	tp -= min(tp, ua);
	if(tp == 0) {
		cout << ans + ta;
		return 0;
	}
	int cost = min(tp, ta);
	ans += (cost * 2);
	tp -= cost;
	ta -= cost;
	if(tp == 0) {
		cout << ans + ta;
		return 0;
	}
	if(ta == 0) {
		cout << ans + 1;
	}
	return 0;
}