#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d\n", max({A + B, A - B, A * B}));
	return 0;
}