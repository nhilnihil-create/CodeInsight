#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 3e4;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	
	int n;
	cin >> n;
	if (n == 3) {
		cout << "2 5 63" << endl;
		return 0;
	}
	if (n == 4) {
		cout << "2 5 20 63" << endl;
		return 0;
	}
	vector<int> ans = {2, 8, 14, 3, 9};
	int p2 = 14 + 6;
	int p3 = 9 + 6;
	int p4 = 4;
	int p6 = 6;
	while ((int)ans.size() + 3 <= n && p2 + 12 <= N) {
		ans.push_back(p2);
		p2 += 6;
		ans.push_back(p2);
		p2 += 6;
		ans.push_back(p2);
		p2 += 6;	
	}
	while ((int)ans.size() + 3 <= n && p4 + 12 <= N) {
		ans.push_back(p4);
		p4 += 6;
		ans.push_back(p4);
		p4 += 6;
		ans.push_back(p4);
		p4 += 6;	
	}
	while ((int)ans.size() + 2 <= n && p3 + 6 <= N) {
		ans.push_back(p3);
		p3 += 6;
		ans.push_back(p3);
		p3 += 6;
	}
	while ((int)ans.size() + 2 <= n && p2 <= N && p4 <= N) {
		ans.push_back(p2);
		p2 += 6;
		ans.push_back(p4);
		p4 += 6;
	}
	while ((int)ans.size() + 1 <= n && p6 <= N) {
		ans.push_back(p6);
		p6 += 6;
	}
	for (auto t : ans) {
		cout << t << ' ';
	} 
	cout << endl;
}
