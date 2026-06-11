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
	string S;
	cin >> S;

	string ans = "AC";
	if (S[0]!='A') ans = "WA";
	int cnt = 0;
	for (int i=2; i<S.size()-1; i++) {
		if (S[i]=='C') {
			S[i] = 'c';
			cnt++;
		}
	}
	if (cnt!=1) ans = "WA";
	for (int i=1; i<S.size(); i++) {
		if (isupper(S[i])) ans = "WA";
	}
	cout << ans << endl;
}