#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int main() {
	int n, m, x, rec;
	cin >> n >> m >> x;
	int cna = 0; int cnb = 0;
	for (int i = 0; i < m; i++) {
		cin >> rec;
		if (rec < x)cna++;
		else cnb++;
	}
	cout << min(cna, cnb) << endl;
	return 0;
}