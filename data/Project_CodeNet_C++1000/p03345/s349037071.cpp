#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int main(){
	int a, b, c;
	long long k;
	scanf("%d %d %d %lld", &a, &b, &c, &k);
	int res = a - b;
	if(k & 1){
		res = -res;
	}
	printf("%d\n", res);
	return 0;
}