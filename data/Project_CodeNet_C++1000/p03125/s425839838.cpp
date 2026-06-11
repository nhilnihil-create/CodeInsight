#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	if(B % A == 0){
		printf("%d\n", A + B);
	}
	else{
		printf("%d\n", B - A);
	}
	return 0;
}