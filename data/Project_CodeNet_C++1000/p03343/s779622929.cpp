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
#define eps 1e-9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, k, Q;
llint a[2005];

bool check(llint x)
{
	for(int i = 1; i <= n; i++){
		llint l = a[i], r = l+x, ret = 0, cnt = 0, len = 0;
		for(int j = 1; j <= n; j++){
			if(a[j] < l){
				ret += min(max(0LL, len-k+1), cnt);
				len = cnt = 0;
			}
			else{
				len++;
				if(a[j] <= r) cnt++;
			}
		}
		ret += min(max(0LL, len-k+1), cnt);
		if(ret >= Q) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> Q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ub = 1e9+7, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}