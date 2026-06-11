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
typedef pair<llint, P> E;

string s;
map<llint, llint> mp;

int main(void)
{
	cin >> s;
	llint n = s.size();
	s = "#" + s;
	
	llint sum = 0; mp[0] = 0;
	for(int i = 1; i <= n; i++){
		llint c = s[i]-'a';
		sum ^= 1<<c;
		
		llint tmp = inf;
		if(mp.count(sum)) tmp = mp[sum]+1;
		for(int j = 0; j < 26; j++){
			if(mp.count(sum^(1<<j))) tmp = min(tmp, mp[sum^(1<<j)]+1);
		}
		if(!mp.count(sum)) mp[sum] = inf;
		mp[sum] = min(mp[sum], tmp);
		if(i == n) cout << tmp << endl;
	}
	
	return 0;
}
