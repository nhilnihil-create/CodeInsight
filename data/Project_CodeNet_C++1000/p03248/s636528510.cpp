#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e5+5;
int n, t, p[N]; char s[N];
int main()
{
    scanf("%s", s+1), n = strlen(s+1);
    if(s[1] == '0'||s[n] == '1') return puts("-1"), 0;
    for(int i = 1; i < n; ++i) if((s[i] == '1') != (s[n-i] == '1')) return puts("-1"), 0;
    p[1] = t = 1; for(int i = 2, j = 1; i < n; ++i) if(s[i] == '1')
    {
        p[i] = ++t, printf("%d %d\n", p[j], p[i]);
        for(int k = 1; k <= i-j-1; ++k) printf("%d %d\n", ++t, p[i]);
        j = i;
    }
    printf("%d %d\n", p[n-1], n);
    return 0;
}