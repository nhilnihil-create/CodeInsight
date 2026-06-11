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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	rep(i, n) cin >> vec[i];
	sort(vec.begin(), vec.end(), greater<int>());
	int sum = 0;
	for (int i=1; i<n; i++) sum += vec[i];
	if (sum <= vec[0]) cout << "No" << endl;
	else cout << "Yes" << endl;
}