#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long i64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 2e5+5, oo = 1e9;
int n, a[N], s[N], top, t[N], b[N], ans;
bool valid(int k)
{
    t[0] = 1; for(int i = 1; i <= n+1; ++i) t[i] = min((i64)t[i-1]*k, (i64)oo);
    s[top = 1] = 1, b[top] = 1;
    for(int i = 1+(a[1] == 1); i <= n; ++i)
    {
        if(s[top] < a[i]) s[++top] = a[i], b[top] = 1;
        else if(s[top] == a[i]) ++b[top];
        else
        {
            while(top>1&&s[top-1] > a[i]) b[top-1] += (b[top]-1)/t[min(s[top]-s[top-1], n+1)], --top;
            if(s[top-1] == a[i]) b[top-1] += (b[top]-1)/t[min(s[top]-s[top-1], n+1)]+1, --top; 
            else b[top] = (b[top]-1)/t[min(s[top]-a[i], n+1)]+2, s[top] = a[i];            
        }
    }
    while(top > 1) b[top-1] += (b[top]-1)/t[min(s[top]-s[top-1], n+1)], --top;
    return b[1] <= k;
}
int main()
{
    n = read(); for(int i = 1; i <= n; ++i) a[i] = read();
    for(int l = 1, r = n, x; l <= r; ) valid(x = (l+r)>>1)?(ans = x, r = x-1):(l = x+1);
    printf("%d\n", ans);
    return 0;
}