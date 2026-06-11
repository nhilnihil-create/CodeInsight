#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	int n;
	cin >> n;
	cout << n/__gcd(n, 2)*2 << endl;

	return 0;
}
