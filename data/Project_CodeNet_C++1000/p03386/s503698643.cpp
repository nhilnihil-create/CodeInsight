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
	int64_t A, B;
	int K;
	cin >> A >> B >> K;
	set<int> s;

	rep(i, K) {
		if (A+i<=B) s.insert(A+i);
		if (B-i>=A) s.insert(B-i);
	}
	for (auto val : s) cout << val << endl;
}