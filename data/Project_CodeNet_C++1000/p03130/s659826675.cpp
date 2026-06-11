#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

int main () {
	vector<int> v(5, 0);
	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]++;
	}	
	int res = 0;
	for (int i = 1; i <= 4; i++) {
		if (v[i] == 0) {
			cout << "NO";
			return 0;
		}
		if (v[i] % 2 == 1)
			res++;
	}
	if (res > 2)
		cout << "NO";
	else
		cout << "YES";
}