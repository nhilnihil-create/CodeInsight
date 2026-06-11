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
	rep(i, n) cin >> vec.at(i);
	sort(vec.begin(), vec.end(), greater<int>());
	int res = 0;
	for (int i=1; i<n; i++) res += vec.at(i);
	res += vec.at(0)/2;
	cout << res << endl;
}