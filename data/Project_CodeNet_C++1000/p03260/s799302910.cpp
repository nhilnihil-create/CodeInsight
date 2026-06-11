#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int num = A * B;

	bool ok = (num==1) || (num==3) || (num==9);


	if (ok){
	cout << "Yes" << "\n";
	} else {
	cout << "No" << "\n";		
	}

	return 0;
}
