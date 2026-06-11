#include <bits/stdc++.h>
using namespace std;

signed main(){
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	printf("%d\n", min(B / A, C));
	return 0;
}