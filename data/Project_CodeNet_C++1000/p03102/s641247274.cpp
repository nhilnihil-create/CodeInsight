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
	int n, m, c, ans=0;
	cin >> n >> m >> c;
	int a, b[100];
	for (int i = 0; i < m;i++)cin >> b[i];
	for (int i = 0;i < n;i++) {
		int cnt = 0;
		for (int j = 0; j < m;j++) {
			cin >> a;
			cnt += a * b[j];
		}
		if (cnt + c > 0)ans += 1;
	}
	cout << ans << endl;
}