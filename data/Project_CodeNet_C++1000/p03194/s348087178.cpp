#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
#include<map>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>

using namespace std;

int sss(long long int x){
	long long int a = 2, sum = 0;
	long long int mx = 0;
	while (x >= a * a) {
		if (x%a == 0) {
			x /= a;
			sum++;
			mx = (mx, sum);
		}
		else { a++; sum = 0; }
	}
	return mx;
}

int main(void) {
	long long int n, p; cin >> n >> p;
	long long int i;
	long long int ans = 0;
	long long int mx = 0;

	if (n == 1) { cout << p << endl; return 0; }
	if (p == 1) { cout << "1" << endl; return 0; }

	for (i = 1; pow(i, n) <= p; i++) {
		long long x = p / pow(i, n);
		if (x == p / pow(i, n)) {
			if (sss(x) < n) {
				ans = i;
			}
		}
	}

	cout << ans << endl;
	return 0;
}