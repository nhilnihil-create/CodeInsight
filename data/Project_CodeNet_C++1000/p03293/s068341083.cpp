#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	int s = (int)S.size();
	string ans = "No";
	for (int i = 0; i < s; i++) {
		if (S == T) ans = "Yes";
		string temp = S.substr(0, s - 1);
		char last = S[s - 1];
		S = last + temp;
	}
	cout << ans << endl;
	return 0;
}