#include<iostream>
using namespace std;
int main() {

	int a,b;
	cin >> a >> b;
	int x = 0;
	for (int i = 0; i < 2; i++) {
		if (a > b) {
			x = x + a;
			a--;
		}
		else {
			x = x + b;
			b--;
		}
	}
	cout << x << endl;
	return 0;


}