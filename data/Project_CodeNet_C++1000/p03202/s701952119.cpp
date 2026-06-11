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
#define LONG_INF 10000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD  998244353
#define REP(i,n) for(long long i = 0;i < n;++i)
vector<int> geko;
int solve(int now) {
	stack<pair<int, int>> next;
	for (int i = 1; i < geko.size(); ++i) {
		if (geko[i] > geko[i - 1]) continue;
		while (next.empty() == false && next.top().first > geko[i]) {
			next.pop();
		}
		int now_go = geko[i];
		int ok = 0;
		while (next.empty() == false && next.top().first == now_go) {
			next.top().second++;
			if (next.top().second == now) {
				next.pop();
				now_go--;
			}
			else {
				ok = 1;
				break;
			}
		}
		if (ok == 0) {
			if (now_go <= 0) return 0;
			next.push(make_pair(now_go, 1));
		}
	}
	return 1;
}
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int a;
		cin >> a;
		geko.push_back(a);
	}
	int tmp = 1;
	for (int i = 1; i < geko.size(); ++i) {
		if (geko[i] <= geko[i - 1])tmp = 0;
	}
	if (tmp == 1) {
		cout << 1 << endl;
		return 0;
	}
	int bot = n+2;
	int top = 1;
	while (bot - top > 1) {
		int mid = (top + bot) / 2;
		if (solve(mid) == 1) {
			bot = mid;
		}
		else {
			top = mid;
		}
	}
	cout << bot << endl;
	return 0;
}