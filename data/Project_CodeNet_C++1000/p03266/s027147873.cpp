#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	long long int n, k;
	cin >> n >> k;
	long long int res = (n / k) * (n / k) * (n / k);
	if (k % 2 == 0) {
		long long int c = n / k;
		if (n / k * k + k / 2 <= n) {
			c++;
		}
		res += c * c * c;
	}
	cout << res << endl;
}
