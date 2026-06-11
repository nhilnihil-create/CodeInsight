#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> bm(m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> bm[i];
	}
	int a;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < m; j++) {
			cin >> a;
			sum += a * bm[j];
		}
		sum += c;
		if (sum > 0) cnt++;
	}
	cout << cnt << endl;
}
