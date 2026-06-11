#include<cstdio>
int a, b;
int main(){
	scanf("%d%d", &a, &b);
	puts(a*b == 15 ? "*" : a+b == 15 ? "+" : "x");
}