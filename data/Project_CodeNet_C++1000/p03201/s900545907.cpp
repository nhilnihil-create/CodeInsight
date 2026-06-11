#include <stdio.h>
#include <set>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

std::multiset<int, std::greater<int>> A;

int main(void){    
    int n; scanf("%d", &n);
    REP(i, n){ int a; scanf("%d", &a); A.insert(a); }
    int cnt = 0;
    for(auto itr = A.begin(); itr != A.end();){
        int t = 1; while(t <= *itr) t <<= 1;
        t -= *itr;
        itr = A.erase(itr);
        auto p = A.find(t);
        if(p == A.end()) continue;
        if(itr == p) itr = A.erase(p);
        else A.erase(p);
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}