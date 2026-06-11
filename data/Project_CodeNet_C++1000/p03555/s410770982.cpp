#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	vector<string> C(2);
	for (int i = 0; i < 2; i++) cin >> C[i];
	if (C[0][0] == C[1][2] && C[0][1] == C[1][1] && C[0][2] == C[1][0]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}