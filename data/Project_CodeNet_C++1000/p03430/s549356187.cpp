/**
  * @brief atcoder
  * @author yao
  */
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <climits>
#define ft first
#define sd second
#ifdef DBG
#   define dbg_pri(x...) fprintf(stderr,x)
#else
#   define dbg_pri(x...) 0
#   define NDEBUG
#endif //DBG
#include <cassert>

typedef unsigned int uint;
typedef long long int lli;
typedef unsigned long long int ulli;

#define N 512

char s[N];
int dp[N][N][N];

int get(int x, int y, int z)
{
    if(x<0||y<0||z<0) return 0;
    return dp[x][y][z];
}

int main()
{
    int n, m;
    scanf("%s%d", s, &m), n = strlen(s);
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)for(int k=0;k<=m;++k)
        dp[i][j][k] = s[i] == s[n-j-1] ?
            get(i-1,j-1,k)+1 :
            std::max(std::max(get(i-1,j,k),get(i,j-1,k)), get(i-1,j-1,k-1)+!!k);
    int ans = 0;
    for(int i=0;i<n;++i) ans = std::max(ans, get(i,n-i-1,m)*2-1);
    for(int i=0;i<n;++i) ans = std::max(ans, get(i,n-i-2,m)*2);
    printf("%d\n", ans);
    return 0;
}
