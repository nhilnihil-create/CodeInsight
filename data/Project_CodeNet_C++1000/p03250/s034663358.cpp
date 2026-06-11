#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int maxVal = max(A, max(B, C));
	
	int ans = 0;
	if (A == maxVal){
		ans = 10*A + B+C;
	} else if (B == maxVal){
		ans = 10*B + A+C;
	} else {
		ans = 10*C + A+B;
	}

	cout << ans << "\n";

	

	return 0;
}
