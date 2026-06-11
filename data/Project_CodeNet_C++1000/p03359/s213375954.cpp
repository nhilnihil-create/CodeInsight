#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	int a, b,c=0;
	cin >> a >> b;
	c = a - 1;
	if (a <= b) c++;
	cout << c << endl;

	return 0;
}