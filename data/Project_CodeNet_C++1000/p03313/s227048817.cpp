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

int N, P;
int A[1<<18];
int X[1<<18][2];
int buf[9];
struct Cmp {
    bool operator()(int i, int j) {
	if (i == -1) return false;
	if (j == -1) return true;
	return A[i] > A[j];
    }
} cmp;

void MAIN() {
    scanf("%d", &N);
    P = 1<<N;
    REP (i, P) scanf("%d", A+i);

    REP (s, P) {
	X[s][0] = s;
	X[s][1] = -1;
    }

    REP (t, N) REP (s, P) if (~s>>t&1) {
	int ns = s | (1<<t);
	buf[0] = X[s][0];
	buf[1] = X[s][1];
	buf[2] = X[ns][0];
	buf[3] = X[ns][1];
	sort(buf, buf+4, cmp);
	int len = unique(buf, buf+4) - buf;
	buf[len] = -1;
	X[ns][0] = buf[0];
	X[ns][1] = buf[1];
    }
    int ma = 0;
    for (int s=1; s<P; s++) {
	amax(ma, A[X[s][0]] + A[X[s][1]]);
	printf("%d\n", ma);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

