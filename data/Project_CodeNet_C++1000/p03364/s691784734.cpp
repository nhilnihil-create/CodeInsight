#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long i64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 3e2+5;
int n, ans; char s[N][N];
bool valid(int A, int B)
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(s[(i+A)%n][(j+B)%n] != s[(j+A)%n][(i+B)%n]) return false;
    return true;
}
int main()
{
    n = read(); for(int i = 0; i < n; ++i) scanf("%s", s[i]);
    for(int i = 0; i < n; ++i) if(valid(i, 0)) ans += n-i;
    for(int i = 1; i < n; ++i) if(valid(0, i)) ans += n-i;
    printf("%d\n", ans);
    return 0;
}