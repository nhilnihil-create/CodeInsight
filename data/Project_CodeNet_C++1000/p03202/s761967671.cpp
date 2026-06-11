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
set<P> S;

bool calc(llint p, llint x, bool flag)
{
	auto it = S.lower_bound(P(p, 0));
	auto pre = it; pre--;
	
	if(it->second < x){
		llint c = it->second;
		if(flag) S.erase(it, S.end());
		else S.erase(it);
		if(pre->first < p-1) S.insert(P(p-1, c));
		S.insert(P(p, c+1));
		return true;
	}
	
	if(pre->second == 0) return false;
	S.erase(it, S.end());
	S.insert(P(p, 1));
	return calc(pre->first, x, false);
}

bool check(llint x)
{
	S.clear();
	S.insert(P(0, 0));
	S.insert(P(a[1], 1));
	
	for(int i = 2; i <= n; i++){
		if(a[i-1] < a[i]){
			S.insert(P(a[i], 1));
			continue;
		}
		if(!calc(a[i], x, true)) return false;
	}
	return true;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ub = n+5, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}
