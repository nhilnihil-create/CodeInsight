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

llint Q;
llint a, b;

llint get(llint x)
{
	llint ub = 1e9+7, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(mid*mid <= x) lb = mid;
		else ub = mid;
	}
	return lb;
}

int main(void)
{
	cin >> Q;
	for(int i = 1; i <= Q; i++){
		cin >> a >> b;
		llint r = get(a*b-1), ans = 2*r;
		if(r*(r+1) > a*b-1) ans--;
		if(min(a, b) <= r) ans--;
		cout << ans << endl;
	}
	
	return 0;
}
