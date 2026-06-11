#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	vector<pair<pair<string, int>, int>> p(n);
	for (int i = 0; i < n; i++) {
		string s;
		int num;
		cin >> s >> num;
		p[i] =  make_pair(make_pair(s, -num), i + 1);
	}
	sort(p.begin(),p.end());
	for (int i = 0; i < n; i++) {
		cout << p.at(i).second << endl;
	}
}