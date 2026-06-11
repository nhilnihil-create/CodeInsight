#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> a(n);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int r = 0;
	int l = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] > x) {
			r++;
		}
		else {
			l++;
		}
	}
	cout << min(r, l);

}