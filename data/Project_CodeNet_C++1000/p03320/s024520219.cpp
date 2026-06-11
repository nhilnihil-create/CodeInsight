#include <bits/stdc++.h>
using namespace std;

pair<long long, int> a[1111];
int top;
void pus(long long x) {
	int sum = 0;
	for (long long y = x; y; y /= 10) sum += y%10;
	while (top > 0 && a[top-1].first * sum > a[top-1].second * x) top --;
	a[top++] = make_pair(x, sum);
}

int main() {
	int k; cin >> k;
	for (int i = 1; i < 1000000; i ++) pus(i); 
	long long cur = 10;
	for (int p = 7; p <= 15; p ++, cur *= 10) {
		for (int i = 100000; i < 1000000; i ++) pus((i+1) * cur - 1);
	}
	for (int i = 0; i < k; i ++) cout << a[i].first << endl;
	return 0;
}