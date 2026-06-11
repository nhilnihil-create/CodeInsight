#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long

using namespace std;
const int maxn = 2e5 + 5;
typedef pair<int, int> P;
int a[maxn];
int n, k, q, ans;
bool check(int o, int p) {
    int ti = 0;
    int x = 0;
    int y = 0;
    for(int i = 0; i <= n; ++i) {
        if(a[i] >= o) {
            if(a[i] <= o + p) {
                x ++;
            } else {
                y ++;
            }
        } else {
            if(y >= k - 1) {
                ti += x;
            } else {
                ti += max(0, x - (k - 1 - y));
            }
            x = 0;
            y = 0;
        }
    }
    return ti >= q;
}
int main() {
#ifdef TT
    freopen("xxx.in", "r", stdin);
#endif // TT
    scanf("%d%d%d", &n, &k, &q);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    a[n] = -1;
    ans = 1e9 + 7;
    for(int i = 0; i < n; ++i) {
        int L = 0, R = 1e9 + 7;
        while(L < R) {
            int mid = (L + R) >> 1;
            if(check(a[i], mid))
                R = mid;
            else
                L = mid + 1;
        }
        ans = min(ans, L);
    }
    cout << ans << endl;
    return 0;
}
