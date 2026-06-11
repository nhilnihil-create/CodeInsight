#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int y;
	char m[2], d[2], c[2];
	cin >> y >> c[0] >> m[0] >> m[1] >> c[1] >> d[0] >> d[1];
	y++;
	cout << y << "/" << m[0] << m[1] << "/" << d[0] << d[1];
	return 0;
}