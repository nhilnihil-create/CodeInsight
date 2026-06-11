#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, D, sum = 0; cin >> N;
	D = N;
	while (N != 0){
		sum += N % 10;
		N /= 10;
	}
//	cout << sum  << "\n";
	cout << ( (D % sum == 0) ? "Yes" : "No") << "\n";
	
	return 0;
}
