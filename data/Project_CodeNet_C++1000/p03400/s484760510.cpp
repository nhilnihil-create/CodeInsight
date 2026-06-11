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
	int N, D, X;
	cin >> N >> D >> X;
	int A[110];
	rep(i, N) cin >> A[i];

	int sum = 0;
	rep(i, N) {
		int num = 0;
		rep(j, D) {
			int d = j*A[i] + 1;
			if (d<=D) num++;
		}
		sum += num;
	}
	cout << sum + X << endl;
}