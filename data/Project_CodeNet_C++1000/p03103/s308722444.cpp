#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint a[100005], b[100005];
P p[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i<= n; i++){
		cin >> a[i] >> b[i];
		p[i] = P(a[i], i);
	}
	sort(p+1, p+n+1);
	
	llint ans = 0, rem = m;
	for(int i = 1; i <= n; i++){
		if(rem <= 0) break;
		llint id = p[i].second;
		llint x = min(rem, b[id]);
		ans += x * a[id], rem -= x;
	}
	cout << ans << endl;
	
	return 0;
}