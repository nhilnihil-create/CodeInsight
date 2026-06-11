#include<iostream>
using namespace std;

int main() {

	int n, a; cin >> n >> a;
	if (n % 500 <= a)cout << "Yes";
	else cout << "No";
	cout << endl;

	return 0;
}