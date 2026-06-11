#include <iostream>
#include <cstdio>
using namespace std;

int d;
int main() {
	cin >> d;
	cout << "Christmas";
	d = 25-d;
	while(d--) cout << " Eve";
	return 0;
}
