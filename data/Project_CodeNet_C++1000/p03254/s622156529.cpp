#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

int n, x, ans;
int a[N];

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    ans = 0;
    for(int i = 1; i <= n; i++) {
        if(x >= a[i]) {
            x -= a[i];
            ans++;
        } else if(x < a[i]) break;
        if(i == n && x > 0) ans--;
    }
    printf("%d\n", ans);
}