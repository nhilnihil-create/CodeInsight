#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	char X, Y;
	cin >> X >> Y;
	if (X < Y) cout << "<" << endl;
	else if (X == Y) cout << "=" << endl;
	else cout << ">" << endl;
	return 0;
}