#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")



int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int alice = 0;
	int bob = 0;
	for (int i = 0; i < n; i += 2) {
		alice += a[i];
	}
	for (int i = 1; i < n; i += 2) {
		bob += a[i];
	}
	cout << alice - bob << endl;
	return 0;
}
