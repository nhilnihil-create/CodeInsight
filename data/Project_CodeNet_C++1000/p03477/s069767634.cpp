#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	if(A + B > C + D){
		printf("Left\n");
	}
	else if(A + B == C + D){
		printf("Balanced\n");
	}
	else{
		printf("Right\n");
	}
	return 0;
}