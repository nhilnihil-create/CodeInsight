#include <stdio.h>
#include <vector>
#include <list>

using lli = long long int;

constexpr int BitSize = 63;
std::vector<lli> A;

int main(void){
    int n, k; scanf("%d%d", &n, &k);
    A.resize(n+1); A[0] = 0;
    for(int x = 1; x <= n; ++x) scanf("%lld", &A[x]);
    for(int x = 1; x <= n; ++x) A[x] += A[x-1];
    std::list<lli> lst;
    for(int x = 0; x <= n; ++x){
        for(int y = x + 1; y <= n; ++y) lst.push_back(A[y] - A[x]);
    }
    lli res = 0;
    for(int pos = BitSize; pos >= 0; pos--){
        if(lst.size() < k) break;
        int cnt = 0;
        for(lli val : lst) if((val >> pos) & 1) cnt++;
        if(cnt < k) continue;
        res += (1LL << pos);
        for(auto itr = lst.begin(); itr != lst.end();){
            if(!( ((*itr) >> pos) & 1)) itr = lst.erase(itr);
            else itr++;
        }
    }
    printf("%lld\n", res);
    return 0;
}