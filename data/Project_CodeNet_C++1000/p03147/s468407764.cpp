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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int n;
	cin >> n;
	int H[n];
	rep(i, n) cin >> H[i];

	int ans = H[n-1];
	for (int i=1; i<n; i++) {
		if (H[i]<H[i-1]) ans += H[i-1] - H[i];
	}
	cout << ans << endl;
}