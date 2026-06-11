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
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
	int n;
	cin >> n;
	vector<vector<int>> geko;
	vector<int> nya;
	nya.push_back(1);
	geko.push_back(nya);
	geko.push_back(nya);
	while (geko[geko.size() - 1][geko[geko.size() - 1].size() - 1] < n) {
		long long now = geko[geko.size() - 1][geko[geko.size() - 1].size() - 1];
		long long maximum = now + geko.size();
		for (int i = 0; i < geko.size(); ++i) {
			geko[i].push_back(now + i + 1);
		}
		vector<int> bobo;
		REP(i, geko.size()) {
			bobo.push_back(now + i + 1);
		}
		geko.push_back(bobo);
	}
	if (geko[geko.size() - 1][geko[geko.size() - 1].size() - 1] != n) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		cout << geko.size() << endl;
		REP(i, geko.size()) {
			cout << geko[i].size();
			REP(q, geko[i].size()) {
				cout << " " << geko[i][q];
			}
			cout << endl;
		}
	}
	return 0;
}