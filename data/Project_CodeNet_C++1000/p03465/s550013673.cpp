#include <cstdio>
#include <cstring>
#include <bitset>
#include <cctype>
#include <algorithm>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 2e3+5, M = 4e6+5;
int n, s; bitset<M> f;
int main()
{
    n = read(), f[0] = 1;
    for(int i = 1, w; i <= n; ++i) w = read(), s += w, f |= f<<w;
    s = (s-1)/2+1;
    for(int i = s; i < M; ++i) if(f[i]) return printf("%d\n", i), 0;
    return 0;
}