#include "bits/stdc++.h"
using namespace std;


int main() {
	int A, B;
	cin >> A >> B;
	int ans = (B - A)*(B - A - 1) / 2;
	ans -= A;
	cout << ans << endl;
}
