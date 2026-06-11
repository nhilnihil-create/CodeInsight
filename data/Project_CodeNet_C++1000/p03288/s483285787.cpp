#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
	int n ;
	cin >> n;
	
	if (n <= 1199)cout << "ABC" << endl;
	else if (n >= 2800) cout << "AGC" << endl;
	else cout << "ARC" << endl;
	return 0;
}