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

int N, A, B;
int S[300011];
int ans[300011];

bool ok() {
    if (N < A || N < B) return false;
    if (A+B > N+1) return false;

    int cnt = 0;
    S[0] = A;
    cnt += A;
    for (int i=1; i<B; i++) {
	S[i] = 1;
	cnt += 1;
    }
    for (int i=1; i<B; i++) {
	int m = min(A - S[i], N - cnt);
	S[i] += m;
	cnt += m;
    }
    if (cnt != N) return false;

    int val = N;
    int pos = 0;
    REP (i, B) {
	for (int k=pos+S[i]-1; k>=pos; k--) {
	    ans[k] = val;
	    val--;
	}
	pos += S[i];
    }
    return true;
}

void MAIN() {
    scanf("%d%d%d", &N, &A, &B);

    if (ok()) {
	rprintf("%d", ans, ans+N);
    } else {
	puts("-1");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

