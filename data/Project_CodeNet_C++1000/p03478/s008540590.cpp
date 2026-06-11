#include<iostream>
using namespace std;
int sum(int a) {
	int ret = 0;
	while (a > 0) {
		ret += a % 10;
		a /= 10;
	}
	return ret;
}
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		int ss = sum(i);
		if (ss<= b && ss >= a) s += i;		
	}
	cout << s;
}