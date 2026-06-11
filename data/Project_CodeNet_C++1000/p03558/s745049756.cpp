#include <bits/stdc++.h>
using namespace std;
int read()
{
    int d = 0, w = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        d = d * 10 + ch - '0', ch = getchar();
    return d * w;
}
void write_(int x)
{
    if (x < 0)
        x = -x, putchar('-');
    if (x > 9)
        write_(x / 10);
    putchar(x % 10 + '0');
}
void writeln(int x)
{
    write_(x);
    putchar('\n');
}
void writesp(int x)
{
    write_(x);
    putchar(' ');
}
int vis[111000];
int main()
{
#ifdef __clang__
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    using P = pair<int, int>;
    int K = read();
    deque<P> de;
    de.push_back({1, 1});
    memset(vis, 0x3f, sizeof(vis));
    while(1)
    {
        P p = de.back();
        de.pop_back();
        if(p.second >= vis[p.first])
            continue;
        vis[p.first] = p.second;
        if(p.first == 0)
        {
            writeln(p.second);
            return 0;
        }
        de.push_back({p.first * 10 % K, p.second});
        de.push_front({(p.first + 1) % K, p.second + 1});
    }
    return 0;
}