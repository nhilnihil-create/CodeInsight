#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100010;
int n, sum[maxn], b[maxn], tree[maxn * 2], a[maxn];
long long tot;
void add(int x) { x += n + 1; for(; x <= n * 2 + 2; x += x & -x) tree[x]++; }
int query(int x) { x += n + 1; int ret = 0; for(; x; x -= x & -x) ret += tree[x]; return ret; }
bool check(int mid) {
    for(int i = 1; i <= n; i++) if(a[i] <= mid) b[i] = 1; else b[i] = -1;
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
    memset(tree, 0, sizeof(tree));
    add(0);
    long long ret = 0;
    for(int i = 1; i <= n; i++) {
        ret += query(sum[i] - 1);
        add(sum[i]);
    }
    return ret >= tot;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = 1e9, ans = 0;
    tot = 1ll * n * (n + 1) / 2; 
    tot = tot / 2 + 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}