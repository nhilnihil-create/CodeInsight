#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXV = (ll)((1 << 18) + 10);

int A[MAXV];

int main() {
	int n;
	scanf("%d", &n);

	for(int i = 0; i < (1 << n);i ++)
		scanf("%d", &A[i]);

	int ans = A[0] + A[1];
	printf("%d\n", ans);
	for(int mask = 2;mask < (1 << n);mask ++){
		int a = 0, b = 0;
		for(int submask = mask;submask * 2 > mask;submask = (submask - 1) & mask){
			if(A[submask] > a)
				b = a, a = A[submask];
			else if(A[submask] > b)
				b = A[submask];
			if(A[submask ^ mask] > a)
				b = a, a = A[submask ^ mask];
			else if(A[submask ^ mask] > b)
				b = A[submask ^ mask];
		}

		ans = max(ans, a + b);
		cout << ans << "\n";
	}

	return 0;
}
