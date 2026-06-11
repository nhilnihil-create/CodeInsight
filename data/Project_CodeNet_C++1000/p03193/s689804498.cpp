#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {

	int n, h, w, a[1000], b[1000],num=0;

	cin >> n >> h >> w;

	for (int k = 0; k < n; k++) {

		cin >> a[k] >> b[k];

		num += min(a[k] / h, b[k] / w);

	}

	cout << num << "\n";

	return 0;
}