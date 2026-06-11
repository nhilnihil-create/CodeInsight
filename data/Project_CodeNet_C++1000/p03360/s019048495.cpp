#include<bits/stdc++.h>

int main(){
	int a, b, c, k;
	scanf("%d %d %d %d", &a, &b, &c, &k);
	if(a<b) std::swap(a, b);
	if(b<c) std::swap(b, c);
	if(a<b) std::swap(a, b);

	while(k--) a *= 2;
	printf("%d\n", a+b+c);
	return 0;
}

