#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using lli = long long int;

lli gcd(lli a, lli b) {
    return (b == 0 ? a : gcd(b, a % b));
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
	lli A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A < B || D < B) {
	    cout << "No" << endl;
	    continue;
	}
	if (C >= B) {
	    cout << "Yes" << endl;
	    continue;
	}
	A %= B;
	D %= B;
	lli g = gcd(B, D);
	lli x = (B - A - 1) / g;
	if (A + g * x <= C) {
	    cout << "Yes" << endl;
	}
	else {
	    cout << "No" << endl;
	}
    }
    return 0;
}
