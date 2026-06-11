#include <utility>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define YES(b) std::cout<< (b ? "Yes" : "No")
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	long long int sum = 0;
	cin >> n;
	vector<int> l(n + 1), r(n + 1);
	REP(i, n) {
		cin >> l[i] >> r[i];
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	REP(i, n + 1) {
		if (l[n - i] > r[i]) {
			sum += (l[n - i] - r[i]) * 2;
		}
	}
	cout << sum;
}
