#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n = 0, a ,b, c = 0, d = 0, e = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		if (a == 1 || b == 1) { n++; }
		if (a == 2 || b == 2) { c++; }
		if (a == 3 || b == 3) { d++; }
		if (a == 4 || b == 4) { e++; }
	}
	if (n == 3 || c == 3 || d == 3 || e == 3) {
		cout << "NO" << endl;
	}
	else { cout << "YES" << endl; }
	cin >> a;
}
