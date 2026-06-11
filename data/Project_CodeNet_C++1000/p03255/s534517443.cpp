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
llint x[200005], c;
llint sum[200005];

int main(void)
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + x[i];
	
	llint ans = inf;
	for(int i = 1; i <= n; i++){
		llint tmp = 0, mul = 5;
		for(int j = 1; j <= n; j+=i){
			tmp += mul*(sum[n+1-j] - sum[max(0LL, n+1-j-i)]);
			tmp = min(tmp, (llint)inf+1);
			if(j > 1) mul += 2;
		}
		ans = min(ans, tmp+c*i);
	}
	ans += n*c;
	cout << ans << endl;
	
	return 0;
}
