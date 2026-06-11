#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, k;

	scanf("%d %d %d %d", &a, &b, &c, &k);

	if(a>b&&a>c){
		a = a*pow(2,k);
		a +=b + c;
		printf("%d\n",a);
	}else if(b>a&&b>c){
		b = b*pow(2,k);
		b +=a + c;
		printf("%d\n",b);
	}else{
		c = c*pow(2,k);
		c +=a + b;
		printf("%d\n",c);
	}

	return 0;
}