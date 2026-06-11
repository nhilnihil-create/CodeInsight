#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;


int main() {
	int n, x;
	int sum = 0;
	int rem = 0;


	cin >> n >> x;
	vector<int>m(n);
	for (int i = 0; i < n; i++)cin >> m[i];

	for (int i = 0; i < n; i++) {
		sum += m[i];
	}
	sort(m.begin(), m.end());
	cout << n+(x - sum) / m[0];
	 
}
