#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;



	bool ok = true;

	if (A != B){
		ok = false;
	}

	if (B != C){
		ok = false;
	}

	if (C != A){
		ok = false;
	}


	if (ok){
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";		
	}

	return 0;
}
