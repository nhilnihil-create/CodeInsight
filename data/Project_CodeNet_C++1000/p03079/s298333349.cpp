#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	double a, b, c, n;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cin >> n;
}