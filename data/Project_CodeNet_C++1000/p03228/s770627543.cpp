#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

int n = 0;

int main() {
	unsigned long long A, B, K;
	cin >> A >> B >> K;
	for (unsigned long long i = 0; i < K; i++) {
		n = 0;
	    if (i % 2 == 0) {
		    if (A % 2 != 0) A--;
		    n = A / 2;
		    A -= n; 
		    B += n;
	    }
	    else {
		    if (B % 2 != 0) B--;
		    n = B / 2;
		    A += n; 
		    B -= n;
	    }
	}
	cout << A << ' ' << B << endl;
	return 0;
}