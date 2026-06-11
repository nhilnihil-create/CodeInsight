#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	if(a+b==15) puts("+");
	else if(a*b==15) puts("*");
	else puts("x");
	return 0;
}
