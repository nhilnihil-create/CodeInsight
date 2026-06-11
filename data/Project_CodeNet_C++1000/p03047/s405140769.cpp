#include<iostream>
#include<cstdio>
using namespace std;

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc == '-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

int main(){
	int a=rd(),b=rd();
	printf("%d",a-b+1);
	return 0;
}