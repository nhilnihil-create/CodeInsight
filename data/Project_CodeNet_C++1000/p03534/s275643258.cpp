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
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
	string s;
	cin >> s;
	map<int, int> wow;
	int tmp = 0;
	REP(i, s.length()) {
		if (wow[s[i]] == 0) tmp++;
		wow[s[i]]++;
	}
	int minnest = 100000;
	int maxe = 0;
	for (int i = 'a';i <= 'c';++i) {
		maxe = max(maxe, wow[i]);
		minnest = min(minnest, wow[i]);
	}
	if (abs(maxe - minnest) <= 1) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}