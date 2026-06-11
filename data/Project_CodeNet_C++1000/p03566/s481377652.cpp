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

llint n;
llint t[105], v[105];
llint l[105], r[105];
llint ub[40005];

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	llint sum = 0;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n; i++) cin >> v[i];
	for(int i = 1; i <= n; i++){
		t[i] *= 2, v[i] *= 2;
		l[i] = sum;
		sum += t[i];
		r[i] = sum;
	}
	
	for(int i = 0; i <= sum; i++) ub[i] = inf;
	for(llint i = 0; i <= sum; i++) ub[i] = min(i, sum-i);
	
	for(int i = 1; i <= n; i++){
		for(int j = l[i]; j <= r[i]; j++) ub[j] = min(ub[j], v[i]);
		for(int j = 0; j <= l[i]; j++) ub[j] = min(ub[j], v[i]+(l[i]-j));
		for(int j = r[i]; j <= sum; j++) ub[j] = min(ub[j], v[i]+(j-r[i]));
	}
	
	double ans = 0;
	for(int i = 1; i <= sum; i++){
		if(ub[i] == ub[i-1]) ans += ub[i];
		else ans += (ub[i]+ub[i-1]) / 2.0;
	}
	ans /= 4;
	printf("%.11f\n", ans);
	
	return 0;
}