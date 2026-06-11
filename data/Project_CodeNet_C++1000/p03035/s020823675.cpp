#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	if(A >= 13){
		printf("%d\n", B);
	}
	else if(A >= 6){
		printf("%d\n", B / 2);
	}
	else{
		printf("0\n");
	}
	return 0;
}