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
	int A, B;
	string S;
	cin >> A >> B >> S;

	string ans = "Yes";
	if (S[A]!='-') ans = "No";
	string first = S.substr(0, A);
	string second = S.substr(A+1, B);

	for (auto s : first) {
		if (!isdigit(s)) ans = "No";
	}
	for (auto s : second) {
			if (!isdigit(s)) ans = "No";
		}
	cout << ans << endl;
}