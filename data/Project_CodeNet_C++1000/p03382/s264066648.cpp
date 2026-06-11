
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e8
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;


int main() {
	
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int mxa = a[n-1];

	int mxr = a[0];
	for (int i = 0; i < n; i++) {
		if (abs(2*a[i] - mxa) < abs(2*mxr - mxa))mxr = a[i];
	}
		
	cout << mxa << " " << mxr << endl;

	return 0;
}