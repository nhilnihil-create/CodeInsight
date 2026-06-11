#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include <sstream>
#include<iomanip>
#include <ctype.h>

//#include<bits/stdc++.h>




using namespace std;
int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int t = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (a <= x&&b <= y)t++;
	}
	cout << t << endl;

	return 0;
}