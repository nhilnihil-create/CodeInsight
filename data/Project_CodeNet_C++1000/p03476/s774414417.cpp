#include <bits/stdc++.h>

using namespace std;
const int N = 100001;
bool is_prime[N];
int c[N] = {};

void sieve() {
	is_prime[0] = is_prime[1] = false; // The numbers 0 and 1 are not prime
	for (int i = 2; i < N; i++) is_prime[i] = true;
	for (int i = 2; i < N; i++) {
		if (is_prime[i]) {
			for (int j = 2; j * i < N; j++) is_prime[j * i] = false;	
		}
	}	
}

int main() {
	sieve();
	for (int i = 1; i < N; i++) {
		if (is_prime[i] && is_prime[(i+1)/2]) {c[i] = c[i-1] + 1;}
		else {c[i] = c[i-1];}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		// int c = 0;
		cout << c[r] - c[l-1] << endl;
	}
	return 0;
}