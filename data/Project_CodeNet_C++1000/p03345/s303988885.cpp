#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	long long A, B, C, K;
	cin >> A >> B >> C >> K;
	if (abs(A - B) > pow(10, 18)) cout << "Unfair" << endl;
	else cout << (K % 2 == 0 ? A - B : B - A) << endl;
}