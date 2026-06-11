#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	long long int a = 0;
	long long int count = 1;
	cin >> a ;
	while (1) {
		if (a == 4 || a == 1 || a == 2) {
			break;
		}
		if (a % 2 == 0) {
			a = a / 2;
		}
		else {
			a = 3 * a + 1;
		}
		count++;
	}
	cout << count + 3 << endl;
	return 0;
}