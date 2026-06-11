#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	int m = max({ a, b, c }) * 3;
	int rest = m - a - b - c;
	cout << (rest % 2 == 0 ? rest / 2 : (rest + 3) / 2) << endl;

	return 0;
}