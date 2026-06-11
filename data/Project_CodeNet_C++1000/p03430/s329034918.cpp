#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, K;
char buf[333];
int dp[333][333][333];

void MAIN() {
    scanf("%s", buf);
    scanf("%d", &K);

    string S = buf;
    string T = buf;
    reverse(T.begin(), T.end());
    N = S.size();

    REP (i, N) REP (j, N) {
	if (S[i] == T[j]) {
	    REP (k, K+1) dp[i+1][j+1][k] = dp[i][j][k] + 1;
	} else {
	    REP (k, K+1) dp[i+1][j+1][k] = max(dp[i][j+1][k], dp[i+1][j][k]);
	    REP (k, K) amax(dp[i+1][j+1][k+1], dp[i][j][k] + 1);
	}
    }

    int ans = 0;
    REP (i, N+1) {
	REP (k, K+1) {
	    int j = N-i;

	    {
		int guess = dp[i][j][k] * 2;
		amax(ans, guess);
	    }

	    if (j) {
		j--;
		int guess = dp[i][j][k] * 2 + 1;
		amax(ans, guess);
	    }
	}
    }
    printf("%d\n", ans);
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

