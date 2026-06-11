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

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		i++;
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		i++;
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n;
llint a[100005], sum[100005];
P p[100005];
BIT bit(100005);
llint L;

bool check(llint m)
{
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1];
		if(a[i] >= m) sum[i]++;
		else sum[i]--;
	}
	for(int i = 0; i <= n; i++) p[i] = P(sum[i], i);
	sort(p, p+n+1);
	
	llint ret = 0;
	bit.init();
	for(int i = 0; i <= n; i++){
		ret += bit.query(p[i].second);
		bit.add(p[i].second, 1);
	}
	return ret >= L;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	L = n*(n+1)/2;
	L = (L+1)/2;
	
	llint ub = 1e9+7, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	cout << lb << endl;
	
	return 0;
}
