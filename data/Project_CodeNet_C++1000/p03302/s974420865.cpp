#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	int n, a, sum = 0; cin >> n >> a;
	if (n + a == 15) {
		cout << '+' << endl;
	}
	else if (n * a == 15) {
		cout << '*' << endl;
	}
	else {
		cout << 'x' << endl;
	}
	cin >> n;
}