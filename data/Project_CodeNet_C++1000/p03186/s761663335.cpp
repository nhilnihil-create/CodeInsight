#include<bits/stdc++.h>
using namespace std;
long long A, B, C;

int main() {
	scanf("%lld%lld%lld", &A, &B, &C);
	C = min(C, A + B + 1);
	printf("%lld\n", B + C);
	return 0;
}