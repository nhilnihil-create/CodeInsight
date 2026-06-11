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
	ll n, m;
	cin >> n >> m;

	ll a, b;
	if (n>=2) a = n-2;
	else a = 1;
	if (m>=2) b = m-2;
	else b = 1;
	cout << a * b << endl;
}