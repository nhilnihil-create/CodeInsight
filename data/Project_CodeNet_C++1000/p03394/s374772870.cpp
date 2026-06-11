#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 3e4+5;
int n;
int main()
{
    n = read();
    if(n == 3) return puts("2 3 25"), 0;
    for(int i = 1, j = n-1; i <= n; ++i, --j)
        if(i%2 == 0&&j%3 != 1&&i <= 5000&&j <= 15000)
        {
            for(int k = 1; k <= i; ++k) printf("%d ", 6*k-3);
            for(int k = 1; k <= j; ++k) printf("%d ", 2*k);
            return puts(""), 0;
        }
    return 0;
}