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
#define mod 1000000007
using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
llint a[200005];
llint dp[200005];
vector<llint> vec[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
	
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		llint p = lower_bound(vec[a[i]].begin(), vec[a[i]].end(), i) - vec[a[i]].begin();
		if(p > 0){
			llint pre = vec[a[i]][p-1];
			if(pre != i-1) dp[i] += dp[pre], dp[i] %= mod;
		}
		dp[i] += dp[i-1], dp[i] %= mod;
	}
	cout << dp[n] << endl;
	
	return 0;
}
