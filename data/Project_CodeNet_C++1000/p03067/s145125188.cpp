#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, a, b, c; cin >> a >> b >> c;
	if (a < c && c < b) {
		cout << "Yes" << endl;
	}
	else if (a > c && c > b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	cin >> n;
}