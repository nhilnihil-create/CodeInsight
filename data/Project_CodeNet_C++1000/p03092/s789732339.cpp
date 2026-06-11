#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
LL A, B;
int P[5011];
int R[5011];
LL dp[5011][5011]; // 200MB

int low[5011];

void MAIN() {
    scanf("%d%lld%lld", &N, &A, &B);
    REP (i, N) scanf("%d", P+i), P[i]--;
    REP (i, N) R[P[i]] = i;

    memset(dp, 0x3f, sizeof dp);
    REP (i, N+1) {
	dp[i][0] = 0;
	dp[0][i] = 0;
	dp[1][i] = 0;
    }

    for (int i=1; i<=N; i++) {
	REP (k, i) if (P[k] > P[i-1]) low[P[k]]++;

	for (int h=1; h<N; h++) {
	    if (i-1 <= R[h]) {
		dp[i][h] = dp[i][h-1];
	    } else {
		amin(dp[i][h], dp[i][h-1] + A);
		amin(dp[i][h], dp[R[h]][h-1] + low[h] * B);
	    }
	}
    }

    printf("%lld\n", dp[N][N-1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

