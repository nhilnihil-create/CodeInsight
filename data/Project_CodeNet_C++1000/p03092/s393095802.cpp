#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 5000;
const ll INF = (1LL << 60);

ll dp[MAXN + 5];

int p[MAXN + 5], N, A, B;
int main() {
	scanf("%d%d%d", &N, &A, &B);
	for(int i=1;i<=N;i++) scanf("%d", &p[i]);
	p[N + 1] = N + 1;
	
	for(int i=1;i<=N+1;i++) {
		dp[i] = INF; int nw = 0; ll del = 0;
		for(int j=i-1;j>=1;j--) {
			if( p[j] < p[i] ) {
				if( nw < p[j] )
					dp[i] = min(dp[i], dp[j] + del), nw = p[j];
				del += B;
			}
			else del += A;
		}
		if( !nw ) dp[i] = del;
	}
	
	printf("%lld\n", dp[N + 1]);
}