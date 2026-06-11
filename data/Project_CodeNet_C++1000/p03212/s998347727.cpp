#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;

ll n;
ll res = 0;

void dfs(ll num, ll a, ll b, ll c) {
	if (num>n) return;
	if (a&&b&&c) res++;
	dfs(num*10+3, 1, b, c);
	dfs(num*10+5, a, 1, c);
	dfs(num*10+7, a, b, 1);
}

int main() {
	cin >> n;
	dfs(0, 0, 0, 0);
	cout << res << endl;
}