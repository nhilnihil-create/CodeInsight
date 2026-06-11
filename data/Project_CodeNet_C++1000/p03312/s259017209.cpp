#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005], sum[200005];

P calc(llint l, llint r)
{
	llint s = sum[r]-sum[l-1];
	
	llint ub = r, lb = l-1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(sum[mid]-sum[l-1] >= s/2) ub = mid;
		else lb = mid;
	}
	P ret = P(-inf, inf);
	if(ub < r){
		llint a = s - (sum[ub]-sum[l-1]), b = sum[ub]-sum[l-1];
		ret.first = max(ret.first, min(a, b));
		ret.second = min(ret.second, max(a, b));
	}
	if(lb >= l){
		llint a = s - (sum[lb]-sum[l-1]), b = sum[lb]-sum[l-1];
		ret.second = min(ret.second, max(a, b));
		ret.first = max(ret.first, min(a, b));
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	
	llint ans = inf;
	for(int i = 3; i <= n-1; i++){
		P res = calc(1, i-1), res2 = calc(i, n);
		ans = min(ans, max(res.second, res2.second) - min(res.first, res2.first));
	}
	cout << ans << endl;
	
	return 0;
}