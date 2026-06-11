#include<bits/stdc++.h>
using namespace std;
char a[5];
int main(){
	scanf("%s",a);
	for(int i=0;i<=2;i++){
		if(a[i]=='9')
			printf("1");
		else
			printf("9");
	}
	printf("\n");
	return 0;
}