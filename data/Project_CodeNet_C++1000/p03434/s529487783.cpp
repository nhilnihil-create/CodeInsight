#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
int lst[110];
bool cmp(int& a, int& b) {
	return a > b;
}
int main() {
	int n;
	int suma=0, sumb=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lst[i];
	}
	sort(lst + 1, lst + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			suma += lst[i];
		}
		else sumb += lst[i];
	}
	cout << suma - sumb << endl;
	return 0;
}