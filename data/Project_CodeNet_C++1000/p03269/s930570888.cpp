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

void MAIN() {
    int L;
    scanf("%d", &L);
    VI A, B, C;
    for (int i=0; i<18; i++) {
	A.push_back(i);
	B.push_back(i+1);
	C.push_back(0);
	A.push_back(i);
	B.push_back(i+1);
	C.push_back(1<<i);
    }

    for (int i=18; i>=0; i--) {
	while (L >= (1<<i)) {
	    A.push_back(i);
	    B.push_back(19);
	    C.push_back(L-(1<<i));
	    L -= 1<<i;
	}
    }
    printf("20 %d\n", (int)A.size());
    REP (i, A.size()) printf("%d %d %d\n", A[i]+1, B[i]+1, C[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

