#include<iostream>
#include<cstdio>
using namespace std;

int main (){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a*b%2==1)
	printf("Odd\n");
	if(a*b%2==0)
	printf("Even\n");
	return 0;
}