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
using ll = long long;


int main() {
	int n;
	cin >> n;
	vector<ll> vec(n);
	vector<ll> vec2(n);
	rep(i, n) cin >> vec.at(i);
	rep(i, n) vec2.at(i) = vec.at(i);
	sort(vec2.begin(), vec2.end());
	ll med = vec2.at(n/2);
	rep(i, n) {
		if (vec.at(i)<med) cout << vec2.at(n/2) << endl;
		else cout << vec2.at(n/2-1) << endl;
	}
}