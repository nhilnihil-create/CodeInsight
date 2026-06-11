#include <stdio.h>
#include <vector>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))

using lli = long long int;
std::vector<int> A;

int main(void){
    int n; scanf("%d", &n);
    A.resize(n); REP(i, n) scanf("%d", &A[i]);

    lli L = 2, R = 2;
    rREP(i, n){
        lli LL = (((L - 1) / A[i]) + 1) * A[i];
        lli RR = (R / A[i]) * A[i] + A[i] - 1;
        L = LL; R = RR;
        if(L > R){
            puts("-1");
            return 0;
        }
    }
    printf("%lld %lld\n", L, R);
    return 0;
}