#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1000000007;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int pr[100010];
void uini(int n) {
	for (size_t i = 0; i <= n; i++)
	{
		pr[i] = i;
	}
}

int parent(int x) {
	if (x == pr[x]) return x;
	return pr[x] = parent(pr[x]);
}

bool unit(int x, int y) {
	int px = parent(x);
	int py = parent(y);

	if (px == py) return false;
	if (px < py) {
		pr[py] = px;
	}
	else {
		pr[px] = py;
	}
	return true;
}

void solv() {

	string s;
	cin >> s;
	int c[3];
	fill(c, c + 3, 0);
	for (size_t i = 0; i < s.size(); i++)
	{
		c[s[i] - 'a']++;
	}
	if (abs(c[0] - c[1]) > 1 || abs(c[0] -c[2]) > 1 || abs(c[2] - c[1]) > 1) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
}


int main() {
	solv();

	return 0;
}
