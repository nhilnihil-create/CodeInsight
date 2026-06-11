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
llint a[200005], b[200005];
vector<llint> vec;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	
	bool flag = true;
	for(int i = 1; i <= n; i++){
		if(a[i] != b[i]) flag = false;
	}
	if(flag){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > b[i]) vec.push_back(b[i]);
		ans += a[i];
	}
	sort(vec.begin(), vec.end());
	
	ans -= vec.front();
	cout << ans << endl;

	return 0;
}
