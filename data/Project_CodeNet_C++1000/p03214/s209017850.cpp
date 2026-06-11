#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, minn, id, s;
	cin >> n;
	vector<int> a(n); 
	s = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		a[i] *= n;
	}
	minn = s * 10;
	for (i = 0; i < n; i++) {
		if (abs(s - a[i]) < minn) {
			minn = abs(s - a[i]);
			id = i;
		}
	}

	cout << id << "\n";

	return 0;
}

