#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

#define forsn(i,s,n) for(int i=(s); i<(int)(n); i++)
#define forn(i,n) forsn(i,0,n)

typedef long long int tint;

int main() {	
	int n; cin >> n;

	int left = 1, right = 1000;
	while (left + 1 < right) {
		int middle = (left + right) / 2;
		if ((middle * (middle - 1)) / 2 <= n) left = middle;
		else right = middle;
	}
	
	if ((left * (left - 1)) / 2 != n) cout << "No\n";
	else {
		cout << "Yes\n";
		vector<vector<int>> res(left, vector<int>());
		
		cout << left << '\n';
		int cur = 1;
		forn(i, left) forsn(j, i + 1, left) {
			res[i].push_back(cur);
			res[j].push_back(cur++);
		}
		
		forn(i, left) {
			cout << res[i].size();
			for (int r : res[i]) cout << " " << r;
			cout << '\n';
		}
	}
}

