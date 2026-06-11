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
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	ll n, k;
	cin >> n >> k;

	ll s = n/k;
	ll res;
	if (k%2==0) {
		ll t = (n+k/2)/k;
		res = s*s*s + t*t*t;
	}
	else {
		res = s*s*s;
	}
	cout << res << endl;
}