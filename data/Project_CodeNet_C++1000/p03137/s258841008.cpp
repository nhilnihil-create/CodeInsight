#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;


	vector<int> x(m);
	vector<int> xx(m-1);
	for (int i = 0; i < m; i++) {
		cin >> x[i];
	}

	if (m == 1) { cout << 0 << endl; return 0; }

	sort(x.begin(), x.end());
	for (int i = 0; i < m-1; i++) {
		xx[i] = x[i+ 1] - x[i];
	}

	sort(xx.begin(),xx.end());

	long long summ = 0;
	for (int i = 0; i < n-1 ; i++) {
		summ += xx.back();
		xx.pop_back();
		if (xx.empty() == true) { break; }
	}
	cout << x[m-1]-x[0]-summ << endl;
	return 0;
}