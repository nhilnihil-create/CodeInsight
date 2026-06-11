#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << min({ abs(A - B) + abs(B - C), abs(A - B) + abs(A - C), abs(B - C) + abs(A - C) }) << endl;
}