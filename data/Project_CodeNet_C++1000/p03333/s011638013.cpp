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
llint l[100005], r[100005];
set<P> lset, rset;

llint calc(llint dir)
{
	for(int i = 1; i <= n; i++){
		lset.insert(P(l[i], i));
		rset.insert(P(r[i], i));
	}
	llint x = 0, y, id, ret = 0;
	while(lset.size()){
		if(dir == 0){
			y = lset.rbegin()->first;
			id = lset.rbegin()->second;
			if(y <= x) break;
		}
		else{
			y = rset.begin()->first;
			id = rset.begin()->second;
			if(y >= x) break;
		}
		ret += abs(x-y), x = y;
		lset.erase(P(l[id], id));
		rset.erase(P(r[id], id));
		dir = 1 - dir;
	}
	ret += abs(x);
	return ret;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	
	llint ans = max(calc(0), calc(1));
	cout << ans << endl;
	
	return 0;
}
