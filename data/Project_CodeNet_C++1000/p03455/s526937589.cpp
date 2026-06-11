#include <bits/stdc++.h>
using namespace std;

signed main(){
	int a, b;
	scanf("%d%d", &a, &b);
	if((a * b) % 2 == 1){
		printf("Odd\n");
	}
	else{
		printf("Even\n");
	}
	return 0;
}