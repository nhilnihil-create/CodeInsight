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
	int s;
	cin >> s;
	int A[1000000];
	int an = s;
	A[an]++;
	int fn;
	bool flg = true;
	int res = 1;
	while(flg) {
		if (an%2==0) fn = an / 2;
		else fn = 3*an + 1;
		an = fn;
		if (A[an] != 0) flg = false;
		A[an]++;
		res++;
	}
	cout << res << endl;
}