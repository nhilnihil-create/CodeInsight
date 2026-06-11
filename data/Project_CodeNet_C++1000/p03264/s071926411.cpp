#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int K;
	cin >> K;
	int odd = 0, even = 0;
	for (int i = 1; i <= K; i++) {
		if (i % 2 == 0) odd++;
		else even++;
	}
	cout << odd * even << endl;
	return 0;
}