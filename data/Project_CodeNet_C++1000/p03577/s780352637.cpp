#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <stack>
#include <queue>
#include <vector>
#define MAX_N 100
#define INF 10000000

using namespace std;


int n;
string s;
int a[200000];

void solve() {
	for (int i = 0; i < s.length()-8; i++) {
		cout << s[i];
	}
	cout << endl;
}

int main() {
	cin >> s;
	solve();
	return 0;
}