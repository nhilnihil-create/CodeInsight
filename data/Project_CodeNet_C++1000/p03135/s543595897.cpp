#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;

#define endl "\n"
#define pb push_back

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
		// freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	double t, x;
	cin >> t >> x;
	cout << fixed << setprecision(3) << (t / x) << endl;
}
