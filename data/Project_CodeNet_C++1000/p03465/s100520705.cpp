#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define MAXN (2000*2010)
bitset<MAXN> bs;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, s, ans;
	cin >> n;
	vector<int> a(n);
	s = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}

	bs.reset();
	bs[0] = 1;
	for (i = 0; i < n; i++) {
		bs |= (bs << a[i]);
	}

	for (i = (s + 1) / 2;; i++) {
		if (bs[i]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	   	 
	return 0;
}
