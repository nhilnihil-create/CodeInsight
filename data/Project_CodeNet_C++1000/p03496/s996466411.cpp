#include <iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <deque>
#include <functional>
#include <initializer_list>
#include <math.h>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <queue>
#include <vector>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); --(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) rFOR(i, 0, (n-1))
#define SORT(A) std::sort((A).begin(), (A).end())
#define ALL(A) (A).begin(), (A).end()
// 座標圧縮 (for vector) : ソートしてから使うのが一般的 ; SORT(A) => COORDINATE_COMPRESSION(A)
#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())

using lli = long long int;
using pii = std::pair<int, int>;

void VintOut(std::vector<int>& A){
    const int n = A.size();
    if(n == 0){putchar('\n'); return;}
    printf("%d", A[0]);
    for(int i = 1; i < n; ++i) printf(" %d", A[i]);
    putchar('\n');
}
void VintOut(std::vector<long long int>& A){
    const int n = A.size();
    if(n == 0){ putchar('\n'); return;}
    printf("%lld", A[0]);
    for(int i = 1; i < n; ++i) printf(" %lld", A[i]);
    putchar('\n');
}

template <typename T>
inline bool chmin(T& a, T b){
    if(b < a){ a = b; return true;}
    return false;
}

template <typename T>
inline bool chmax(T& a, T b){
    if(a < b){ a = b; return true;}
    return false;
}

inline bool bitUP(int state, int k){ return (state >> k) & 1; }
inline bool bitUP(long long int state, int k){ return (state >> k) & 1;}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//-100 -200 10

constexpr int inf = 1e9 + 334;
std::vector<int> A;

int main(void){
    int n; scanf("%d", &n);
    A.resize(n); REP(i, n) scanf("%d", &A[i]);

    int Mx = -inf, argMx;
    int mn = inf, argMn;
    REP(i, n){
        if(A[i] < mn) mn = A[i], argMn = i;
        if(A[i] > Mx) Mx = A[i], argMx = i;
    }
    argMx++; argMn++;

    printf("%d\n", 2 * n - 1);

    if(Mx + mn >= 0){
        for(int i = 1; i <= n; ++i) printf("%d %d\n", argMx, i);
        for(int i = 1; i + 1 <= n; ++i) printf("%d %d\n", i, i + 1);
    }
    else{
        for(int i = 1; i <= n; ++i) printf("%d %d\n", argMn, i);
        for(int i = n; i - 1 >= 1; --i) printf("%d %d\n", i, i - 1);
    }



    
    return 0;
}