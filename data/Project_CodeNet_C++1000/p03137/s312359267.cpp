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
	int n, m;
	cin >> n >> m;
	int X[m];
	rep(i, m) cin >> X[i];
	sort(X, X+m);

	int D[m-1];
	for(int i=0; i<m-1; i++) D[i] = X[i+1] - X[i];
	sort(D, D+m-1);

	int sum = 0;
	for (int i=0; i<m-n; i++) sum += D[i];
	cout << sum << endl;
}