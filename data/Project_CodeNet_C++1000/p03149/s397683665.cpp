#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[4];
int main() {
	for(int i=0; i<4; i++) cin >> a[i];
	sort(a, a+4);
	cout << (a[0]==1 && a[1]==4 && a[2]==7 && a[3]==9 ? "YES" : "NO");
	return 0;
}
