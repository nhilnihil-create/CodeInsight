#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	int k,a=0,b=0;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		if (i % 2 == 0) a++;
		else b++;
	}
	cout << a * b << endl;

	return 0;
}
