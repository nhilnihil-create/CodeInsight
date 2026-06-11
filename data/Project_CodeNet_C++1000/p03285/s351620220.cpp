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
	int N;
	cin >> N;

	rep(i, N/4+1) {
		rep(j, N/7+1) {
			if ((4*i+7*j)==N) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}