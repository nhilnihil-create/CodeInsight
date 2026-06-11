#include <bits/stdc++.h>

using namespace std;

const int N = 31;
int n, m;
int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            cnt[a]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        if(cnt[i] == n)
            ans++;
    }

    cout << ans;

    return 0;
}
