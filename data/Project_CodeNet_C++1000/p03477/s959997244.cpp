#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>
#include<queue>
#include<bitset>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	auto A = a + b;
	auto B = c + d;

	if (A == B) {
		cout << "Balanced" << endl;
	}else if (A > B) {
		cout << "Left" << endl;
	}
	else if (A < B) {
		cout << "Right" << endl;
	}
}