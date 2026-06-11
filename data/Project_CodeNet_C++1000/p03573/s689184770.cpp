#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int ans;
	if (A == B) ans = C;
	else if (B == C) ans = A;
	else if (C == A) ans = B;
	cout << ans << endl;
	return 0;
}