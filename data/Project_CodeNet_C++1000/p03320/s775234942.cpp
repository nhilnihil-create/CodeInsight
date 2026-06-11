#include<iostream>
using namespace std;

int sum(long long x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	int k; cin >> k;
	long long num = 1, add = 1;
	while (k--) {
		cout << num << endl;
		while (double(num + add) / sum(num + add) > double(num + 2 * add) / sum(num + 2 * add))add *= 10;
		num += add;
	}
	return 0;
}