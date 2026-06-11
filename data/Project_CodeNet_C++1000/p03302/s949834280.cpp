#include <iostream>
#include <cstdio>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	if(a*b==15) putchar('*');
	else if(a+b==15) putchar('+');
	else putchar('x');
	return 0;
}