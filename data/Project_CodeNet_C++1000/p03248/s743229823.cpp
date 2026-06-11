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

string s;

int main(void)
{
	cin >> s;
	llint n = s.size();
	if(s.back() == '1'){
		cout << -1 << endl;
		return 0;
	}
	s.pop_back();
	
	string t = s;
	reverse(t.begin(), t.end());
	if(s.front() == '0' || s != t){
		cout << -1 << endl;
		return 0;
	}
	
	cout << 1 << " " << 2 << endl;
	int v = 2;
	for(int i = 3; i <= n; i++){
		cout << v << " " << i << endl;
		if(s[i-2] == '1') v = i;
	}
	
	return 0;
}
