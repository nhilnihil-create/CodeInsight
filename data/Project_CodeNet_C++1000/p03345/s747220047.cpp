#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	long A, B, C, K;
	cin >> A >> B >> C >> K;

	if( K%2 == 0 ) {
		cout << A-B << endl;
	}
	else {
		cout << B-A << endl;
	}

	return 0;
}
