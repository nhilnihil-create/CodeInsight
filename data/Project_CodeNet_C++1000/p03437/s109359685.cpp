#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int X, Y;
	cin >> X >> Y;
	cout << (X%Y == 0 ? -1 : X) << endl;

	return 0;
}
