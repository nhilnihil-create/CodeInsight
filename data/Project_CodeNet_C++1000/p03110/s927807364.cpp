#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
using ll = long long;



int main() {
	int n;
	double x, sum = 0.0;
	string u;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> u;
		if (u == "BTC") sum += (380000 * x);
		else sum += x;
	}

	cout << sum << endl;

	return 0;
}