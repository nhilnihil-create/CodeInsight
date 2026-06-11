#include <iostream>
using namespace std;

int h(int x) {
	int sum = 0;
	for (int i = x; i != 0; i--) {
		sum += i; 
	}
	return sum;
}

int main() {
	int a, b;
	cin >> a >> b;
	h(b - a);
	cout << h(b - a) - b << endl;
}