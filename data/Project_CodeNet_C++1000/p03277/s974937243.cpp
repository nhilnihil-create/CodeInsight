#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
using namespace std;
const int N = 1e5 + 9, M = 2e5 + 9;
const int inf = 0x3f3f3f3f;
int a[N], s[N], tr[M], n;
int lowbit(int x) { return x & (-x); }
void add(int x){ while(x < M) tr[x]++, x += lowbit(x); }
ll query(int x){
    ll res = 0;
    while(x > 0) res += tr[x], x -= lowbit(x);
    return res;
}
bool check(int x){
    ll res = 0;
    rep(i, 1, n) s[i] = s[i-1] + (a[i] >= x ? 1 : -1);
    memset(tr, 0, sizeof tr);
    rep(i, 0, n) res += query(s[i] + N), add(s[i] + N);
    return res * 2 >= 1ll * n * (n+1) / 2; 
}
int erfen(int l, int r){
    int res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) res = mid, l = mid+1;
        else r = mid-1;
    }
    return res;
}
int main(){
    int minn = inf, maxx = 0;
    scanf("%d", &n);
    rep(i, 1, n) {
        scanf("%d", &a[i]);
        maxx = max(maxx, a[i]), minn = min(minn, a[i]);
    }
    printf("%d", erfen(minn, maxx));
    return 0;
}