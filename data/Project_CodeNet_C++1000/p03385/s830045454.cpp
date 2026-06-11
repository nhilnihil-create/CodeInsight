#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string S;
	cin >> S;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < 3; i++) {
		if (S[i] == 'a') a++;
		else if (S[i] == 'b') b++;
		else if (S[i] == 'c') c++;
	}
	if (a == 1 && b == 1 && c == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}