#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int lst[3] = { 1,100,10000 };
int main() {
	int d, n;
	cin >> d >> n;
	if (n == 100) {
		cout << lst[d] * (n + 1) << endl;
	}
	else {
		cout << lst[d] * n << endl;
	}
	return 0;
}