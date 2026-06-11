#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e6 + 5;
char s[maxn];
int sum[maxn];
int k[maxn];
int n;
LL slove(int k)
{
    queue<int> q;
    int j = 1, pre = 0;
    LL ans = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if(s[i] != 'D')
            continue;
       // cout << "i " << i << ' ';
        while(!q.empty()) {
            if(i > q.front()) {
                ans -= sum[q.front()] - sum[pre];
                q.pop();
            }
            else
                break;
        }
        if(pre)
            ans -= LL(sum[i] - sum[pre]) * q.size();
        j = max(j, i);
        for (; j < i + k && j <= n; j++) {
            if (s[j] == 'C')
                q.push(j), ans += sum[j] - sum[i];
        }
        res += ans;
       // cout << "res " << res << '\n';
        pre = i;
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
        scanf("%d", &k[i]);
    for (int i = 1; i <= n; i++) {
        // if (s[i] == 'D')
        //     D.push_back(i);
        // if (s[i] == 'C')
        //     C.push_back(i);
        if (s[i] == 'M')
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", slove(k[i]));
    }
    return 0;
}
// 6
// DMCDMC
// 1
// 6