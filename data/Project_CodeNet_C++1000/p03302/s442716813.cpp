#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a+b==15)printf("+");
	if(a*b==15)printf("*");
	if(a*b!=15&&a+b!=15) printf("x");
}