#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>  
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD  998244353
#define REP(i,n) for(long long i = 0;i < n;++i)
int main(){
	iostream::sync_with_stdio(false);
	int h, w,n;
	cin >> h >> w >> n;
	vector<pair<int, int>> gogo;
	REP(i, n) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		gogo.push_back(make_pair(b,a - b));//y,x
	}
	sort(gogo.begin(), gogo.end());
	int ans = h;
	if (n == 0) {
		cout << ans << endl;
		return 0;
	}
	int top = -1;
	int bot = 1;
	int done = 0;
	for (int i = 0; i < gogo.size(); ++i) {
		swap(gogo[i].first, gogo[i].second);
		if (i == 0) {
			if (gogo[i].second != 0) {
				done = 1;
			}
		}
		if (i != 0) {
			if (gogo[i].second - gogo[i - 1].second > 1) {
				top = 300000;
				done = 1;
			}
		}
		if (top == -1) {
			if (gogo[i].first >= 1) {
				top = gogo[i].first;
			}
		}
		if (bot <= gogo[i].first&&gogo[i].first <= top) {
			ans = min(ans, gogo[i].first + gogo[i].second);
		}
		if (bot - 1 == gogo[i].first) {
			bot++;
		}
		if (done == 0&&top == gogo[i].first) {
			top++;
		}
	}
	cout << ans << endl;
}
