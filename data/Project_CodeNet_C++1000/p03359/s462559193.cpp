#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int takahashi = 0;
	if (a <= b) takahashi += a;
	else takahashi += a - 1;
	cout << takahashi << endl;
	return 0;
}