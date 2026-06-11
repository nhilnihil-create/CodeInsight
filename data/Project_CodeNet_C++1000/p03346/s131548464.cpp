#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		a[p[i] - 1] = i;
	}

	int res, cnt; res = cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] < a[i])res++;
		else res = 1;		
		cnt = max(cnt, res);
	}
	cout << n - cnt << endl;

	return 0;
}