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
long long s[100010], t[100010];
int main() {
	int a, b, q;
	cin >> a >> b >> q;
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < q; i++) {
		long long ans = 1000000000000000000;
		long long x;
		cin >> x;
		auto it = upper_bound(s, s + a, x);
		long long co, co1;
		if (it == s + a) {
			co = 1000000000000000000;
		}
		else {
			co = *it;
		}
		if (it == s) {
			co1 = 1000000000000000000;
		}
		else {
			co1 = *(it - 1);
		}
		auto itr = upper_bound(t, t + b, co);
		long long co2;
		if (itr == t + b) {
			co2 = 1000000000000000000;
		}
		else {
			co2 = *itr;
		}
		long long co3;
		if (itr == t) {
			co3 = 1000000000000000000;
		}
		else {
			co3 = *(itr - 1);
		}
		itr = upper_bound(t, t + b, co1);
		long long co4;
		if (itr == t + b) {
			co4 = 1000000000000000000;
		}
		else {
			co4 = *itr;
		}
		long long co5;
		if (itr == t) {
			co5 = 1000000000000000000;
		}
		else {
			co5 = *(itr - 1);
		}
		if (min(abs(co - x), abs(co2 - x)) + abs(co2 - co) < ans) {
			ans = min(abs(co - x), abs(co2 - x)) + abs(co2 - co);
		}
		if (min(abs(co - x), abs(co3 - x)) + abs(co3 - co) < ans) {
			ans = min(abs(co - x), abs(co3 - x)) + abs(co3 - co);
		}
		if (min(abs(co1 - x), abs(co4 - x)) + abs(co1 - co4) < ans) {
			ans = min(abs(co1 - x), abs(co4 - x)) + abs(co1 - co4);
		}
		if (min(abs(co1 - x), abs(co5 - x)) + abs(co1 - co5) < ans) {
			ans = min(abs(co1 - x), abs(co5 - x)) + abs(co1 - co5);
		}
		cout << ans << endl;
	}
	return 0;
}
