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
string s;
bool b7, b5, b3;
int ans = 0;
void bfs(string a) {
	if (a.size() >= s.size()) {
		return;
	}
	a += '7';
	b7 = false, b5 = false, b3 = false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '7') {
			b7 = true;
		}
		if (a[i] == '5') {
			b5 = true;
		}
		if (a[i] == '3') {
			b3 = true;
		}
	}
	if (b7 == true && b5 == true && b3 == true) {
		if (s.size() > a.size() || s >= a) {
			ans++;
		}
	}
	bfs(a);
	a.erase(a.end()-1,a.end());
	a += '5';
	b7 = false, b5 = false, b3 = false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '7') {
			b7 = true;
		}
		if (a[i] == '5') {
			b5 = true;
		}
		if (a[i] == '3') {
			b3 = true;
		}
	}
	if (b7 == true && b5 == true && b3 == true) {
		if (s.size() > a.size() || s >= a) {
			ans++;
		}
	}
	bfs(a);
	a.erase(a.end() - 1, a.end());
	a += '3';
	b7 = false, b5 = false, b3 = false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '7') {
			b7 = true;
		}
		if (a[i] == '5') {
			b5 = true;
		}
		if (a[i] == '3') {
			b3 = true;
		}
	}
	if (b7 == true && b5 == true && b3 == true) {
		if (s.size()>a.size()||s >= a) {
			ans++;
		}
	}
	bfs(a);
	a.erase(a.end() - 1, a.end());
}
int main() {
	cin >> s;
	string n = "";
	bfs(n);
	cout << ans << endl;
	return 0;
}