#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll X, Y;
	cin >> X >> Y;

	if (X % Y == 0){
		cout << -1 << "\n";	
	} else {
		ll prod = 1;
		ll val = X;
		while (val <= 1e18) {
			if (val % Y != 0){
				cout << val << "\n";
				return 0;
			}
			prod++;
			val = X * prod;
		}
		cout << -1 << "\n";			
	}



	return 0;
}
