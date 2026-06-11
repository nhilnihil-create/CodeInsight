#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
	long n;
	vector<long> a;
	vector<long> l;
	long asum = 0, bsum = 0;;
	cin >> n;
	for (long i = 0; i < n; i++) {
		long t;
		cin >> t;
		a.push_back(t);
		asum += t;
	}
	bool flag = false;
	long po = 0, ng = 0;
	long nnum = 0;
	for (long i = 0; i < n; i++) {
		long t;
		cin >> t;
		//b.push_back(t);
		bsum += t;
		if (t > a[i]) {
			flag = true;
		}
		long dif = a[i] - t;
		l.push_back(dif);
		if (dif < 0) {
			ng += dif;
			nnum++;
		}
		else {
			po += dif;
		}
	}
	if (!flag) {
		cout << "0" << endl;
		return 0;
	}
	if (asum < bsum) {
		cout << "-1" << endl;
		return 0;
	}

	sort(l.begin(), l.end(), greater<long>());
	long cnt = 0;
	for (auto e : l) {
		cnt++;
		ng += e;
		if (ng >= 0) {
			break;
		}
	}
	cout << cnt + nnum << endl;

	return 0;
}