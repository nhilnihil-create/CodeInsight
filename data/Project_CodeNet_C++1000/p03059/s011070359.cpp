#include<iostream>
using namespace std;
int main() {
	int a, b, t;
	cin >> a >> b >> t;
	int bb = 0;
	int aa = 0;
	while (aa + a <= t) {
		bb = bb + b;
		aa = aa + a;
	}
	cout << bb << endl;
	return 0;

}