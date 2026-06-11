#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[9];
int main() {
	for(int i=0; i<6; i++) cin >> a[i];
	sort(a, a+5);
	cout << (a[4]-a[0]<=a[5] ? "Yay!" : ":(");
	return 0;
}
