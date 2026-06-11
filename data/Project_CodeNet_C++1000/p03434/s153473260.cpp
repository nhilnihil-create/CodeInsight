#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int A = 0;
	int B = 0;
	for (int i = 0; i < N/2; i++) {
		A += a[2*i];
		B += a[2*i + 1];
	}
	if (N % 2 == 1) {
		A += a[N - 1];
	}
	cout << A-B << endl;
	return 0;
}