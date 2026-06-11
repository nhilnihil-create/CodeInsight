#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n,m,x;
	cin >> n >> m >> x;
	vector<int> a(n + 1,0);
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		a.at(b) = 1;
	}
	int l=0, r=0;
	for (int i = 0; i < x; i++) {
		l += a.at(i);
	}
	for (int i = x; i < n + 1; i++) {
		r += a.at(i);
	}
	int sum=(l < r) ? l : r;
	cout << sum;
}