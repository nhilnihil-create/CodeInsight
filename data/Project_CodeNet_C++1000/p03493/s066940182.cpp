#include <iostream>
#include <cstdio>
using namespace std;

string a;
int main() {
	cin >> a;
	cout << (a[0]=='1') + (a[1]=='1') + (a[2]=='1');
	return 0;
}
