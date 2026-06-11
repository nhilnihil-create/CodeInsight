#include<iostream>
using namespace std;

int main() {
	int n, a, b; cin >> n >> a >> b;

	int maxAns, minAns;
	maxAns = (a>=b?b:a);
	minAns = (a + b > n ? a + b - n : 0);
	cout << maxAns << ' ' << minAns << endl;

	return 0;
}