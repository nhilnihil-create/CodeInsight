// Written By NewbieChd
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int BUF = 1000000;
char buf[BUF], *p1, *p2;
inline char getChar() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUF, stdin), p1 == p2) ? EOF : *p1++; }
inline long long read() {
    long long f = 0;
    char c;
    while (!isdigit(c = getChar())) {}
    do
        f = f * 10 + (c ^ 48);
    while (isdigit(c = getChar()));
    return f;
}

const int maxN = 100003;
long long d[maxN];
map<long long, int> mp;

int ind[maxN];
inline bool cmp(int x, int y) { return d[x] > d[y]; }

int siz[maxN];
vector<int> g[maxN];
long long dfs(int x) {
    long long o = 0;
    for (int y : g[x])
        o += dfs(y) + siz[y];
    return o;
}

int main() {
    int n = read(), i, x, y;
    long long tmp;
    for (i = 1; i <= n; ++i)
        d[i] = read(), mp[d[i]] = i, ind[i] = i, siz[i] = 1;
    sort(ind + 1, ind + n + 1, cmp);
    for (i = 1; i < n; ++i) {
        x = ind[i], tmp = d[x] - n + (siz[x] << 1);
        if (mp.find(tmp) == mp.end() || siz[x] << 1 == n) {
            printf("-1\n");
            return 0;
        }
        y = mp[tmp], g[y].push_back(x), siz[y] += siz[x];
    }
    
    if (dfs(ind[n]) == d[ind[n]])
        for (x = 1; x <= n; ++x)
            for (int y : g[x])
                printf("%d %d\n", x, y);
    else
        printf("-1\n");
    return 0;
}
