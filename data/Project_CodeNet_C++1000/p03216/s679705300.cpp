#include <iostream>
#include <limits>
#include <cfenv>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
#include <random>
#include <math.h>
#include <random>
#include <functional>


#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))
#define ALL(TheArray) TheArray.begin(), TheArray.end()

using lli = long long int;
using pii = std::pair<int, int>;

template <class T> inline bool chmax(T& a, T b){
    if(a < b){a = b; return true;}
    return false;
}
template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

constexpr int MAX_SIZE = 1e6;
char str[MAX_SIZE + 10];
std::vector<int> D;
std::vector<lli> A;

lli solve(int n, int k){
    // A[i] := [i, i+k)で作れるMCの数
    A[0] = 0;
    lli res = 0;
    int i, j;
    int m = 0, c = 0;
    for(j = 0; j < k; ++j){
        if(str[j] == 'M')  m++;
        else if(str[j] == 'C'){ c++; A[0] += m; }
    }
    for(i = 1; i < n; ++i){
        A[i] = A[i-1];
        if(str[i-1] == 'M'){
            m--; A[i] -= c;
        }
        else if(str[i-1] == 'C') c--;

        if(j < n){
            if(str[j] == 'M')  m++;
            else if(str[j] == 'C'){ c++; A[i] += m; }
            j++;
        }
    }


    for(int v : D) res += A[v];

    return res;
}



int main(void){
    int n; scanf("%d", &n);
    scanf("%s", str);

    REP(i, n) if(str[i] == 'D') D.push_back(i);

    A.resize(n+1);

    int q; scanf("%d", &q);
    // クエリに答える
    while(q--){
        int query; scanf("%d", &query);
        printf("%lld\n", solve(n, query));
    }

    return 0;
}