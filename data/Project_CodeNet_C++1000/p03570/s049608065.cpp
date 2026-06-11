#include <stdio.h>
#include <array>
#include <bitset>
#include <cstring>
#include <map>
#include <iterator>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}

constexpr int inf = 1e9;
constexpr int N = 2e5;
char str[N+10];
constexpr int ALPHA_SIZE = 'z' - 'a' + 1;
// A[i][j] = [0, i)の中の char<'a'+ j>の個数の偶奇
std::array<std::bitset<ALPHA_SIZE>, N+1> A;
std::array<int, N+1> DP;

int main(void){
    scanf("%s", str);
    const int n = strlen(str);
    REP(i, n){A[i+1] = A[i]; A[i+1].flip(str[i] - 'a');}

    std::map<int, int> minDist; minDist[0] = 0; DP[0] = 0;
    for(int i = 1; i <= n; ++i){
        DP[i] = DP[i-1] + 1;
        int v = A[i].to_ulong();
        std::map<int, int>::iterator itr; 
        REP(j, ALPHA_SIZE){
            int nv = v ^ (1 << j);
            itr = minDist.find(nv);
            if(itr != minDist.end()) chmin(DP[i], itr->second + 1);
        }
        itr = minDist.find(v);
        if(itr == minDist.end()) minDist[v] = DP[i];
        else if(DP[i] > itr->second + 1) DP[i] = itr->second + 1;
        else if(DP[i] < itr->second)     minDist[v] = DP[i];
    }
    printf("%d\n", DP[n]);
    return 0;
}