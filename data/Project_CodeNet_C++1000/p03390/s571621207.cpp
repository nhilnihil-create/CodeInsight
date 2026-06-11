#include <bits/stdc++.h>
using namespace std;

using Int = long long;

int main() {
	Int Q;
	cin >> Q;
	while ( Q-- ) {
		Int A, B;
		cin >> A >> B;
		if ( A > B ) swap(A, B);
		
		if ( B - A <= 1 ) cout << 2*A-2 << endl;
		else {
			Int C = (Int)sqrt(A*B);
			if ( C*C == A*B ) C--;
			if ( C*(C+1) >= A*B ) cout << 2*C-2 << endl;
			else cout << 2*C-1 << endl;
		}
	}

	return 0;
}
