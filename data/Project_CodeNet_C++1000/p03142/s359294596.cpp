#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<stdio.h>
#include <cstdint>
#include <stdlib.h> 
#include <time.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) REP(i,1,n+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define RNG(x, a, n) &((x)[a]), &((x)[n])
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> PII;
typedef vector<ll> Vl;
typedef vector<int> VI;
typedef tuple<int, int, int> TT;
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define dmt(x, y, z) make_tuple(x, y, z)
#define pb(x) push_back(x)
#define pf(x) push_front(x)
const int MAX = 5100000;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const ll longinf = 1LL << 60;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };



int n, m;
vector<PII> ans;
Vl g[100005];
ll h[100005];


int main() {

	cin >> n >> m;
	rep(i, n - 1 + m) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		h[y]++;
	}

	queue <int> q;

	rrep(i, n)if (h[i] == 0)q.push(i);

	int s = q.front();
	ans.push_back(dmp(s, 0));

	while (!q.empty()) {
		int tmp = q.front(); q.pop();

		rep(i, g[tmp].size()) {
			h[g[tmp][i]]--;
			if (h[g[tmp][i]] == 0) {
				ans.pb(dmp(g[tmp][i], tmp));
				q.push(g[tmp][i]);
			}
		}
	}

	sort(ans.begin(), ans.end());

	rep(i, ans.size()) {
		cout << ans[i].se << endl;
	}

	return 0;
}
