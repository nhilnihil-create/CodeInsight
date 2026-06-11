#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int A, B;
		scanf("%d%d", &A, &B);
		if(A > B)swap(A, B);
		long long fac = 1ll * A * B;
		int x = sqrt(1. * fac);
		int ans = 2 * x;
		if(1ll * x * x == fac)ans -= 2;
		else if((fac - 1) / x == x)ans--;
		if(A != B)ans--;
		if(A != 1 && (fac - 1) / ((fac - 1) / B) == B)ans--; 
		printf("%d\n", ans);
	}
}