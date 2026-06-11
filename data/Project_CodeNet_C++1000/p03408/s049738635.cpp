#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	int m, n;
	cin >> m;

	vector<string> s(m);
	for (int i = 0; i < m; i++)cin >> s[i];

	cin >> n;
	vector<string> t(n);
	for (int i = 0; i < n; i++)cin >> t[i];

	map<string, int> u;

	for (int i = 0; i < m; i++) {
		u[s[i]]++;
	}

	for (int i = 0; i < n; i++) {
		u[t[i]]--;
	}

	int count = 0;
	for (auto b : u) {

		if (count < b.second)count = b.second;
	}
	cout << count << endl;

	return 0;
}
