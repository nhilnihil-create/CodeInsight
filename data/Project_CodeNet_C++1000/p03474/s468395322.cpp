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
	int a, b;
	char s;
	string ans="Yes";
	cin >> a >> b;
	for (int i = 0;i < a;i++) {
		cin >> s;
		if (!(s >= '0' && s <= '9')) {
			ans = "No";
		}
	}
	cin >> s;
	if (s != '-')ans = "No";
	for (int i = 0;i < b;i++) {
		cin >> s;
		if (!(s >= '0' && s <= '9')) {
			ans = "No";
		}
	}
	cout << ans << endl;
}