#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	int n, l;
	int a[55];
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i + j > n || i + j > l) {
				continue;
			}
			vector<int> v;
			for (int k = 0; k < i; k++) {
				v.emplace_back(a[k]);
			}
			for (int k = n - 1; k >= n - j; k--) {
				v.emplace_back(a[k]);
			}
			sort(v.begin(), v.end());
			int sum = 0;
			for (int k = 0; k < v.size(); k++) {
				sum += v[k];
			}
			for (int k = 0; k < v.size(); k++) {
				if (i + j + k > l) {
					continue;
				}
				if (sum > m) {
					m = sum;
				}
				sum -= v[k];
			}
		} 
	}
	cout << m << endl;
	return 0;
}