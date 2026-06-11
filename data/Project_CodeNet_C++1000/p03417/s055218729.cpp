#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, M;
	cin >> N >> M;

	ll ans = 0;
	if ( (N==1) || (M==1) ){
		if (N*M == 1){
			ans = 1;
		} else {
			ans = N*M - 2;
		}
	} else if ((N==2) || (M==2)) {
		ans = 0;
	} else {
		ans = N*M - 2*(N + M) + 4;
	}

	cout << ans << "\n";

	return 0;
}
