#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 87;
const int M = N * 2;
int n,a[N],f[M];
void add(int i)
{
    for (; i < M; i += i & -i)
        ++f[i];
}
int qry(int i)
{
    int r=0;
    for (; i ; i ^= i & -i)
        r += f[i];
    return r;
}
bool ok(int k)
{
    memset(f,0,sizeof(f));
    int s = N;
    add(s);
    long long t = (n * (n + 1LL) / 2 + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        s += a[i] >= k ? 1 : -1;
        t -= qry(s);
        add(s);
    }
    return t <= 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int lo = 1, hi = 1e9;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (ok(mi))
            lo = mi + 1;
        else
            hi = mi - 1;
    }
    cout << hi << '\n';
}
