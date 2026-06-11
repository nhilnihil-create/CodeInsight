#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int main(){
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	if((b - a) % 2 == 0){
		printf("Alice\n");
	}else{
		printf("Borys\n");
	}
	return 0;
}