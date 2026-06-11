#include <iostream>
#include <cstdio>
using namespace std;

long long a, b, k, c;
int main() {
	cin >> a >> b >> k;
	for(int i=0; i<k; i++) {
		if(i%2==0) {
			if(a&1) a--;
			c = a/2;
			a -= c;
			b += c;
		} else {
			if(b&1) b--;
			c = b/2;
			b -= c;
			a += c;
		}
	}
	cout << a << ' ' << b;
	return 0;
}