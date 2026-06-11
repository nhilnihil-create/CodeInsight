#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	if(n == 25) {
		cout << "Christmas";
	} else if(n == 24) {
		cout << "Christmas Eve";
	} else if(n == 23) {
		cout << "Christmas Eve Eve";
	} else {
		cout << "Christmas Eve Eve Eve";
	}
	return 0;
}