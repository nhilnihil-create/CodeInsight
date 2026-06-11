#include<iostream>
using namespace std;

int main() {
	int n, a, b; cin >> n >> a >> b;
	int dist = b - a;
	cout << (dist % 2 == 0 ? "Alice" : "Borys") << endl;

	return 0;
}