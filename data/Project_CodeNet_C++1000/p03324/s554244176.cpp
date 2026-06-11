#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int a, b;
	cin >> a >> b;
	if (a == 0) {
		if (b == 100) 
		   b++;
		cout << b;
	}else if (a == 1) {
		int x = b * 100;
		if (b == 100) // 10100
			x += 100;
		cout << x;
	}else {
		int x = b * 10000;
		if (b == 100) 
		    x += 10000;
		cout << x;
	}
}
