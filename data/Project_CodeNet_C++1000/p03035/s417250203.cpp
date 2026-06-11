#include "bits/stdc++.h"
using namespace std;

int main() {
	int A,B;
	cin >> A>>B;
	int ans=B;
	if (A<=12&& A>=6) {
		ans = B / 2;
	}
	else if(A<=5){
		ans = 0;
	}
	cout << ans<<endl;
	return 0;
}