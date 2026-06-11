#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;

int main() {
	int n, x, d;
	cin >> n >> d >> x;
	int a;
	int ans = x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ans += (d - 1) / a+1;
	}
	cout << ans << endl;
	return 0;
}