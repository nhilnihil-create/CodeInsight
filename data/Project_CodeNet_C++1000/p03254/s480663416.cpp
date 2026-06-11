#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	int n, x,cnt=0;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int i = 0;
	while (i<n-1) {
		if (x >= a[i]) {
			x -= a[i];
			i++;
			cnt++;
		}else break;
	}
	if (x == a[i]) {
		cnt++;
	}
	cout << cnt << endl;
}