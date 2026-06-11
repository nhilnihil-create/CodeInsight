#include<stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if (a <= 5)printf("0");
	else if (a <= 12) printf("%d", b / 2);
	else printf("%d", b);
}