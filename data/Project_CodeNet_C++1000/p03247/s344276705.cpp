#include <cstdio>

typedef long long ll;

const int MAXN = 1000;

ll X[MAXN + 5], Y[MAXN + 5]; int N;

ll abs(ll x) {
	return x >= 0 ? x : -x;
}

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%lld%lld", &X[i], &Y[i]);
	int type = ((X[1] + Y[1]) & 1);
	for(int i=1;i<=N;i++) {
		if( type != ((X[i] + Y[i]) & 1) ) {
			type = -1;
			break;
		}
	}
	if( type == -1 ) {
		puts("-1");
		return 0;
	}
	else if( type == 0 ) {
		printf("%d\n%d", 40, 1);
		for(int i=0;i<39;i++)
			printf(" %lld", (1LL<<i));
		puts("");
		for(int i=1;i<=N;i++) {
			putchar('L'), X[i]++;
			for(int j=0;j<38;j++) {
				ll t1 = (1LL << j), t2 = (1LL << (j + 1)), t3 = (1LL << (j + 2));
				if( abs(X[i] % t2) == t1 ) {
					if( abs(Y[i] % t3) + abs((X[i] + t1) % t3) == t2 )
						putchar('L'), X[i] += t1;
					else putchar('R'), X[i] -= t1;
				}
				else {
					if( abs(X[i] % t3) + abs((Y[i] + t1) % t3) == t2 )
						putchar('D'), Y[i] += t1;
					else putchar('U'), Y[i] -= t1;
				}
			}
			ll t1 = (1LL << 38), t2 = (1LL << 39), t3 = (1LL << 40);
			if( abs(X[i] % t2) == t1 ) {
				if( abs(Y[i] % t3) + abs((X[i] + t1) % t3) == t2 )
					puts("R"), X[i] -= t1;
				else puts("L"), X[i] += t1;
			}
			else {
				if( abs(X[i] % t3) + abs((Y[i] + t1) % t3) == t2 )
					puts("U"), Y[i] -= t1;
				else puts("D"), Y[i] += t1;
			}
		}
	}
	else {
		printf("%d\n", 40);
		for(int i=0;i<40;i++)
			printf("%lld ", (1LL<<i));
		puts("");
		for(int i=1;i<=N;i++) {
			for(int j=0;j<39;j++) {
				ll t1 = (1LL << j), t2 = (1LL << (j + 1)), t3 = (1LL << (j + 2));
				if( abs(X[i] % t2) == t1 ) {
					if( abs(Y[i] % t3) + abs((X[i] + t1) % t3) == t2 )
						putchar('L'), X[i] += t1;
					else putchar('R'), X[i] -= t1;
				}
				else {
					if( abs(X[i] % t3) + abs((Y[i] + t1) % t3) == t2 )
						putchar('D'), Y[i] += t1;
					else putchar('U'), Y[i] -= t1;
				}
			}
			ll t1 = (1LL << 39), t2 = (1LL << 40), t3 = (1LL << 41);
			if( abs(X[i] % t2) == t1 ) {
				if( abs(Y[i] % t3) + abs((X[i] + t1) % t3) == t2 )
					puts("R"), X[i] -= t1;
				else puts("L"), X[i] += t1;
			}
			else {
				if( abs(X[i] % t3) + abs((Y[i] + t1) % t3) == t2 )
					puts("U"), Y[i] -= t1;
				else puts("D"), Y[i] += t1;
			}
		}
	}
}