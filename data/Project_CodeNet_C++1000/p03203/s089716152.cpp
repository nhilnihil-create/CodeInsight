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
	int h, w, n;
	cin >> h >> w >> n;
	set<pair<int, int> > s;
	vector<int> miny(200001, mod);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		s.insert(make_pair(x, y));
		miny[x] = min(miny[x], y);
	}
	int maxy = 1;
	if(s.find(make_pair(2, 1)) != s.end()){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 2; i < h; i++){
		if(s.find(make_pair(i, maxy + 1)) == s.end()) maxy++;
		if(miny[i + 1] <= maxy){
			cout << i << endl;
			return 0;
		}
	}
	cout << h << endl;
}