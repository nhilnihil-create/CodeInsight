#include<iostream>

using namespace std;

int main() {
	int a, b, n;

	cin >> n >> a >> b;

	int l = 0, r = 0;

	l = n * a;

	if (l == b)
		cout << b << endl;
	else if(l<b)
		cout << l << endl;
	else
		cout << b << endl;
}
