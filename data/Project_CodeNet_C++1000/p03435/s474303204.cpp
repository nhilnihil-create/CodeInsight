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
	int C[3][3];
	rep(i, 3) {
		rep(j, 3) cin >> C[i][j];
	}
	int cnt = 0;
	for (int j=0; j<3; j++) {
		for (int i=j+1; i<3; i++) {
			if (C[0][j]-C[0][i]==C[1][j]-C[1][i] && C[0][j]-C[0][i]==C[2][j]-C[2][i]) cnt++;
			}
	}
	if (cnt==3) cout << "Yes" << endl;
	else cout << "No" << endl;
}