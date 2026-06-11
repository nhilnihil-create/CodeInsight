#include <iostream>
#include <string>
#include <vector>
#include <valarray>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main() {
	long long n, x, temp = 0, i;
	cin >> n >> x;
	valarray<int>a(n);
	for (auto& i : a)
	{
		cin >> i;
	}
	sort(begin(a), end(a));
	for (i = 0; i < n; i++) {
		if (temp + a[i] <= x) {
			temp += a[i];
		}
		else {
			break;
		}
	}
	if (i == n && x > temp)
		i--;
	cout << i << endl;
}