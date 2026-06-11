#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	long long X, Y;
	cin >> X >> Y;
	if (X % Y == 0) cout << "-1" << endl;
	else cout << X << endl;
	return 0;
}