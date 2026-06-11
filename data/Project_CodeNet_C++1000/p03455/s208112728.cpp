#include<iostream>
using namespace std;

int main(void) {
	int a, b;

	cin >> a >> b;
	if (a % 2 == 0 || b % 2 == 0) printf("Even\n");
	else printf("Odd\n");

	return 0;
}