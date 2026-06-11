#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[2] * 10 + a[1] + a[0] << endl;

	return 0;
}
