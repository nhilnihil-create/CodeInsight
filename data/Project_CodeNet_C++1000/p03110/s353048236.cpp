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
	double res = 0.0;
	rep(i, n) {
		double x;
		string u;
		cin >> x;
		cin >> u;
		if (u=="JPY") res += x;
		else res += 380000.0 * x;
	}
	cout << fixed << setprecision(5);
	cout << res << endl;
}