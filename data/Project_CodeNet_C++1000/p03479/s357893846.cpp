#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	ll x, y;
	cin >> x >> y;
	int p = 0;
	while (x <= y) {
		x = x * 2;
		p++;
	}
	cout << p;
}



