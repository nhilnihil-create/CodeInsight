#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#define ll long long

using namespace std;

int MOD = 998244353;
ll int n, a, b, k;
ll int fak[500010];

ll int put (ll int x, ll int y) {
	x*=y;
	return x%MOD;
}

ll int pot (ll int x, int p) {
	if (p == 0) {
		return 1;
	}
	if (p == 1) {
		return x;
	}
	if (p%2 == 0) {
		ll int y = pot(x, p/2);
		return put(y, y);
	}
	return put(pot(x, p-1), x);
}

ll int divajd (ll int x, ll int y) {
	y = pot(y, MOD-2);
	x*=y;
	return x%MOD;
}

ll int povrh (int x) {
	return divajd(fak[n], put(fak[n - x], fak[x]));
}

int main() {
	
	cin >>n >>a >>b >>k;
	
	fak[0] = 1;
	for (int i=1; i<n+1; i++) {
		fak[i] = put(fak[i-1], i);
	}
	
	ll int br = 0;
	for (int i=0; i<n+1; i++) {
		if ((k-i*a)%b == 0 && (k-i*a)/b <= n) {
            int B = (k-i*a)/b;
            if (B >= 0) {
                int A = i;
                br+=put(povrh(A), povrh(B));	
            }
		}
	}
	cout <<br%MOD;
				
	return 0;
}