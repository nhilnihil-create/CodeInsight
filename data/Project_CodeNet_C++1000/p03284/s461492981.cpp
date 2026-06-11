#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
using ll = long long;



int main() {
	int n, k;
	cin >> n >> k;
	if (n % k == 0) cout << "0" << endl;
	else cout << "1" << endl;

	return 0;
}
