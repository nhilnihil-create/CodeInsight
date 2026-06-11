#include<bits/stdc++.h>
#define N 200000
typedef long long LL;
using namespace std;
int a[N], b[N], n, k;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
    LL ans = 0;
    for(int i = 0; i <= 30; i++)
        if (k & (1 << i)) {
            int tmp = ((k >> (i + 1)) << (i + 1)) + (1 << i) - 1;
            LL sum = 0;
            for(int j = 1; j <= n; j++)
                if ((tmp | a[j]) == tmp) sum += b[j];
            ans = max(ans, sum);
        }
    LL sum = 0;
    for(int i = 1; i <= n; i++)
        if ((k | a[i]) == k) sum += b[i];
    ans = max(ans, sum);
    cout << ans << endl;
}
