#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, A;
	cin >> N >> A;
	int remainder = N - (N / 500 * 500);
	if (A >= remainder) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}