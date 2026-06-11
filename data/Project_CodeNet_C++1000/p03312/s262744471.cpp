#include <stdio.h>
#include <algorithm>
using namespace std;

int N; long long A[200200];

int main()
{
	scanf ("%d",&N);
	for (int i=1;i<=N;i++) scanf ("%lld",&A[i]), A[i] += A[i-1];

	long long ans = 1e18;

	for (int i=2;i<=N-2;i++){
		int p = lower_bound(A+1,A+N+1,A[i]/2) - A;
		int q = lower_bound(A+1,A+N+1,(A[i]+A[N])/2) - A;
		for (int a=-1;a<=0;a++) for (int b=-1;b<=0;b++){
			int x = p + a, y = q + b;
			if (x < 1 || x > i || y <= i || y > N) continue;
			long long mx = max({A[x],A[i]-A[x],A[y]-A[i],A[N]-A[y]});
			long long mn = min({A[x],A[i]-A[x],A[y]-A[i],A[N]-A[y]});
			ans = min(ans,mx-mn);
		}
	}
	printf ("%lld\n",ans);

	return 0;
}