#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;

	scanf("%d %d",&a, &b);

	int mul = a*b;

	if(mul<(a+b)){
		mul=a+b;
	}
	if (mul<(a-b)){
		mul=a-b;
	}
	printf("%d\n",mul);

	return 0;
}