#include <iostream>
using namespace std;
int main()
{
	int a, b, h=0;
	cin >> a >> b;
	for (int i = 1; i < 1000; i++) {
		h += i;
		if (b - a == i) {
			cout << h - b << endl;
		}
	}
}