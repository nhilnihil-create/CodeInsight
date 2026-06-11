#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int A, B, C;
	cin >> A >> B >> C;

	if( C < A && C < B ) {
		cout << "No" << endl;
	}
	else if( C > A && C > B ) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}
