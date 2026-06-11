#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	double otoshidama = 0;
	for (int i = 0; i < N; i++) {
		double x;
		string u;
		cin >> x >> u;
		if (u == "JPY") otoshidama += x;
		if (u == "BTC") otoshidama += x * 380000;
	}
	cout << fixed << setprecision(5) << otoshidama << endl;
	return 0;
}