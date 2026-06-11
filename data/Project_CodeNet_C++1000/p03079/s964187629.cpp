#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
int a , b , c ;

int main() {
	cin >> a >> b >> c ;
	if(a == b && b == c) printf("Yes\n") ;
	else printf("No\n") ;
	return 0 ;
}