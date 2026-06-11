/* 考察欄 : 元の盤面を M1, 新しい盤面を M2とすると
          for (i, j) in [n]^2:
              M2[i, j]=M2[j, i] <===> M1[i-A, j-B] = M1[j-A, i-B]
          i-A = x, j-B = y とし, z = A-Bとすれば
                                <===> M1[x, y] = M1[x-z,y+z]
          したがって, 候補は高々 -n < A-B < n で O(n)個 : O(n^2)で調べることが可能
          ~~~~~> 全体で O(n^3)でおk
*/
#include <stdio.h>
#include <cstring>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

constexpr int N = 300;
char str[N][N+10];

bool judge(int n, int d){
    REP(x, n) REP(y, n) if(str[x][y] != str[(y+n+d)%n][(x+n-d)%n]) return false;
    return true;
}

int main(void){
    int n; scanf("%d", &n);
    REP(i, n) scanf("%s", str[i]);
    int res = 0;
    for(int d = -(n-1); d < n; ++d) if(judge(n, d))
                            res += n - (d < 0 ? -d : d);
    
    printf("%d\n", res);
    
    
    return 0;
}