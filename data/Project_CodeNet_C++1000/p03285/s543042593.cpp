#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	string ans = "No";
	for (int cake = 0; cake <= 25; cake++) {
		for (int donut = 0; donut <= 14; donut++) {
			if (4 * cake + 7 * donut == N) ans = "Yes";
		}
	}
	cout << ans << endl;
	return 0;
}