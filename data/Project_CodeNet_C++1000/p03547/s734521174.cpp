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

using namespace std;

int main() {
	char A, B;
	cin >> A >> B;

	if (A == B) {
		cout << "=" << endl;
	}
	else if (A < B) {
		cout << "<" << endl;
	}
	else {
		cout << ">" << endl;
	}
}