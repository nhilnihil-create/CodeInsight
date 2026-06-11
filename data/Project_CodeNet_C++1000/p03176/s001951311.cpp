#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5, mod = 1e9 + 7;
typedef pair<int, int> ii;
int a[maxn], h[maxn], n;
long long fen[maxn];
void update(int x, long long val)
{
    for(int i=x; i<maxn; i+=i&(-i)) fen[i] = max(fen[i], val);
}
long long get(int x)
{
    long long res = 0;
    for(int i=x; i>=1; i-=i&(-i)) res = max(res, fen[i]);
    return res;
}

int main()
{
    #ifdef NTMA 
        freopen("abc.inp", "r", stdin);
    #endif
    //memset(f, 255, sizeof(f));
    long long ans = 0;
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> h[i];
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {
        long long res = get(h[i]-1) + a[i];
        update(h[i], res);
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}