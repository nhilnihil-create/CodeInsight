#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int res = 0;
	int in = min(a, b);
	int ax = max(a, b);
	res += ax;
	ax--;
	res += max(in, ax);
	cout << res << endl;
	return 0;
}