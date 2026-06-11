#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, sum, mi, a[105];
double avg, mn=1e9;
int main() {
	int i;
	cin >> n;
	for(i=0; i<n; i++) cin >> a[i], sum += a[i];
	avg = 1.0 * sum / n;
	for(i=0; i<n; i++) {
		if(abs(a[i] - avg) < mn) mn = abs(a[i] - avg), mi = i;
	}
	cout << mi;
	return 0;
}
