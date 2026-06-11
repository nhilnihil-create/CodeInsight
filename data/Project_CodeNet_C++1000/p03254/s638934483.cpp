#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, x;
	cin >> N >> x;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int n = 0;
	while (1) {
		if (x >= a[n]) {
			x -= a[n];
			n++;
		}
		else {
			break;
		}
		if (n == N && x > 0) {
			n--;
			break;
		}
		else if (n == N && x == 0) {
			break;
		}
	}
	cout << n << endl;
	return 0;
}