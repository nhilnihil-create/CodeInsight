#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;
 
ll n;
int arr[maxn];
int tree[maxn * 2];
 
int get_idx(int x) {
    return x + maxn;
}
 
void update(int x) {
    while(x < maxn * 2) {
        ++tree[x];
        x += x & -x;
    }
}
 
int query(int x) {
    int ret = 0;
    while(x) {
        ret += tree[x];
        x -= x & -x;
    }
    return ret;
}
 
int main(void) {
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", arr + i);
    int st = 1, ed = 1e9;
    int ans = INT_MAX;
    while(st <= ed) {
        int mid = st + ed >> 1;
 
        ll cnt = 0;
        memset(tree, 0, sizeof(tree));
        int base = 0;
        for(int i = 1; i <= n; ++i) {
            int now = arr[i] < mid ? -1 : 1;
            base += now;
            update(get_idx(now - base));
            cnt += query(get_idx(-base - 1));
        }
 
        //printf("%d %lld\n", mid, cnt);
 
        if(cnt <= n * (n + 1) / 4) { 
            st = mid + 1;
            ans = mid;              
 
        }
        else {
            ed = mid - 1;
        }
    }
    printf("%d", ans);
    return 0;
}