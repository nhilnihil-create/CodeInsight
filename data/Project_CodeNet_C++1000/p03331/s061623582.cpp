#include <bits/stdc++.h>
using namespace std;

int main(){
	int num;
	scanf("%d",&num);
	int resp=0;

	while(num){
		resp = resp +num%10;
		num = num/10;
	}
	if(resp==1){
		printf("10\n");
	}else{
		printf("%d\n",resp);
	}
	

	return 0;
}