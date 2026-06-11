#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5, inf = INT_MAX, mod = 1e9 + 7;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int n, profit[102][12];
    bool days[102][12];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            cin >> days[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 11; j++)
            cin >> profit[i][j];
    int mask = 0, ans = INT_MIN;
    while (mask < (1 << 10) - 1)
    {
        mask++;
        int cnt[102] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 10; j++)
                if ((mask & (1 << j)) != 0 && days[i][j])
                    cnt[i]++;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += profit[i][cnt[i]];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}