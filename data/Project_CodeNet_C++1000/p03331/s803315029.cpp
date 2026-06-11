#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef long long i64;
typedef pair<int, i64> pii;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
int n, ans; int w(int i) { return i?w(i/10)+i%10:0; }
int main()
{
    n = read(), ans = 1e9;
    for(int i = 1; i < n; ++i) ans = min(ans, w(i)+w(n-i));
    printf("%d\n", ans);
    return 0;
}