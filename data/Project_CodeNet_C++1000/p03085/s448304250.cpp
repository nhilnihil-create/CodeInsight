#include<iostream>
using namespace std;
int main() {
	char rec;
	cin >> rec;
	char ans;
	if (rec == 'A') {
		ans = 'T';
	}
	else if (rec == 'C') {
		ans = 'G';
	}
	else if (rec == 'G') {
		ans = 'C';
	}
	else {
		ans = 'A';
	}
	cout << ans << endl;
	return 0;
}