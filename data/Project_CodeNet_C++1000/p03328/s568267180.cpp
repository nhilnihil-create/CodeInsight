#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a, b, c;
int main(){
	scanf("%d%d", &a, &b);
	c = b - a;
	printf("%d\n", c * (c + 1) / 2 - b);
	return 0;
} 