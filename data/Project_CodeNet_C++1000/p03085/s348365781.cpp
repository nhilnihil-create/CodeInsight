#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
	char a;
	cin >> a;
	if (a == 'A') {
		cout << 'T' << endl;
		return 0;
	}
	if (a == 'T') {
		cout << 'A' << endl;
		return 0;
	}
	if (a == 'G') {
		cout << 'C' << endl;
		return 0;
	}
	if (a == 'C') {
		cout << 'G' << endl;
		return 0;
	}
	return 0;
}
