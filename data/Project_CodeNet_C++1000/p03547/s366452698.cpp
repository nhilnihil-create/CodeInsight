#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	char X, Y;
	scanf("%c %c", &X, &Y);
	if (X < Y) printf("<\n");
	else if (X > Y) printf(">\n");
	else printf("=\n");
	return 0;
}
