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
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint n;
llint a[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -1;
	
	llint ans = 0;
	for(int i = n+1; i >= 1; i--){
		if(a[i-1] < a[i]-1){
			cout << -1 << endl;
			return 0;
		}
		if(a[i-1] > a[i]-1) ans += a[i-1];
	}
	cout << ans << endl;
	
	return 0;
}
