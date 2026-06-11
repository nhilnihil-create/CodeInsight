#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long MOD = 1e9 + 7;
using namespace std;
typedef long long ll;

map<ll, int> mp;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, h, w;
	cin >> n >> h >> w;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= h && b[i] >= w) counter++;
	}
	cout << counter << endl;
	return 0;
}