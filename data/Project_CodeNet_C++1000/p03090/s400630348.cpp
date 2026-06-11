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
bool ans[105][105];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			ans[i][j] = true;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(n%2) ans[i][n-i] = false;
		else ans[i][n+1-i] = false;
	}
	
	vector<P> avec;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i >= j) continue;
			if(ans[i][j]) avec.push_back(P(i, j));
		}
	}
	
	cout << avec.size() << endl;
	for(int i = 0; i < avec.size(); i++) cout << avec[i].first << " " << avec[i].second << endl;
	
	return 0;
}
