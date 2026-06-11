#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long n, a, b, c, s;
int main() {
	cin >> n;
	while(n--) {
		cin >> a >> b;
		if(a > b) swap(a, b);
		c = sqrt(a*b);
		if(c*c < a*b) {
			s = 2*c - 1;
			if(a<=c) s--;
			if(c*(c+1) < a*b) s++;
		} else {
			s = 2*c - 2;
			if(a<c) s--;
		}
		cout << s << endl;
	}
	return 0;
}