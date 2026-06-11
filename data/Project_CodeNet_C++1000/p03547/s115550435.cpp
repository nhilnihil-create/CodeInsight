#include "bits/stdc++.h"
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	if (A>B) {
		cout << ">"<<endl;
	}
	else if (A<B) {
		cout << "<"<<endl;
	}
	else {
		cout << "="<<endl;
	}
	return 0;
}