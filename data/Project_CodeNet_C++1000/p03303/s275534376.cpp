#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	string S;
	int w;
	cin >> S >> w;

	for( int i = 0; i < S.size(); i += w ) {
		cout << S[i];
	}

	cout << endl;

	return 0;
}
