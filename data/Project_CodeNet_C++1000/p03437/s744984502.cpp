#include <iostream>
#include <cstdio>
using namespace std;

long long x, y;
int main() {
	cin >> x >> y;
	if(x%y==0) puts("-1");
	else {
		for(int i=2; ; i++) {
			if(x*i % y > 0) return printf("%lld", x*i) * 0;
		}
	}
	return 0;
}
