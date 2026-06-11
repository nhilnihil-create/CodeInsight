#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ldb n, m, d; cin >> n >> m >> d;

	if (d == 0) printf("%.10Lf\n", (m - 1) / n);
	else printf("%.10Lf\n", (m - 1) * (2 * (n - d)) / (n * n));	
}
