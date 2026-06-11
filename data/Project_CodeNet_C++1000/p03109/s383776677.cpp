#include <iostream>
#include <cstdio>
using namespace std;

int a, b, c;
int main() {
	scanf("%d/%d/%d", &a, &b, &c);
	a = a*10000 + b*100 + c;
	cout << (a<=20190430 ? "Heisei" : "TBD");
	return 0;
}
