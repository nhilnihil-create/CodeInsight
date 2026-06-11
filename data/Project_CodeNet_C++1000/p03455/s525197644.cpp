#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int a,b;

int main(void) {
	cin >> a >> b;
	if((a * b) & 1) puts("Odd");
	else puts("Even");
	return 0;
} 