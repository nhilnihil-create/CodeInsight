#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int pos[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i;
    }
    int ans = n;
    int cur = 1;
    while (cur <= n)
    {
        int index = pos[cur++];
        int cnt = 1;
        while (cur <= n && pos[cur] > index)
        {
            index = pos[cur];
            cur++;
            cnt++;
        }
        ans = min(ans, n - cnt);
    }
    cout << ans << endl;
    return 0;
}
