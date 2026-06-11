#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	scanf("%d",&k);
	if(k&1)
		printf("%d\n",(k/2)*(k/2+1));
	else 
		printf("%d\n",(k/2)*(k/2));
	return 0;
} 