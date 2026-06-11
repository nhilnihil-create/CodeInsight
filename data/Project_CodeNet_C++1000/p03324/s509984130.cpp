#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int D, N; 
    cin >> D >> N;
 
	int S = 1; 
    for (int i = 0; i < D; i++) {
        S *= 100;
    }
	if (N <= 99) {
		cout << S * N << endl;
	}
	else {
		cout << S * 101 << endl;
	}
}

