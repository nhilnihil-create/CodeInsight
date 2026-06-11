#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	map<long long int, int> d_map;
	for(int i = 0; i < n; i++){
		long long int tmp;
		cin >> tmp;
		d_map.insert(make_pair(tmp, i));
	}
	vector<long long int> s(n, 1);
	vector<long long int> dps(n, 0);
	set<pair<int, int> > ans;
	for(auto i = d_map.rbegin(); i != d_map.rend(); i++){
		int now = i->second;
		long long int nowd = i->first;
		long long int nextd = nowd + 2 * s[now] - n;
		if(nextd >= nowd || d_map.find(nextd) == d_map.end()) continue;
		int next = d_map[nextd];
		s[next] += s[now];
		dps[next] += s[now] + dps[now];
		ans.insert(make_pair(min(now, next), max(now, next)));
	}
	if(ans.size() != n - 1 || dps[(*d_map.begin()).second] != (*d_map.begin()).first){
		cout << -1 << endl;
		return 0;
	}
	for(auto i = ans.begin(); i != ans.end(); i++){
		cout << i->first + 1 << " " << i->second + 1 << endl;
	}
}