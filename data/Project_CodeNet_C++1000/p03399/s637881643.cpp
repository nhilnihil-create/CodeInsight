#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;




int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a > b) a = b;
	if (c > d) c = d;
	cout << a + c << endl;

	return 0;
}
