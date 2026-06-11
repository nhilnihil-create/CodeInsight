#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define Int int64_t
using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> b(m, { 0,0 });
	for (int i = 0; i < m; i++) {
		cin >> b[i].second >> b[i].first;
	}

	sort(b.begin(), b.end());

	int c = 1;

	int bb = b[0].first-1;

	for (int i = 1; i < m; i++) {
		if (b[i].second > bb ) {
			bb = b[i].first - 1;
			c++;
		}
	
	}

	cout << c << endl;


}