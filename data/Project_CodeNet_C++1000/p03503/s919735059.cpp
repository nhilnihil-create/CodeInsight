#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int f[N][10];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> f[i][j];
        }
    }
    int p[N][11];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> p[i][j];
        }
    }

    int ans = -1* (1e9+7);
    for (int bit = 1; bit < 1<<10; bit++)
    {
        int d[10];
        for (int i = 0; i < 10; i++)
        {
            if((bit >> i & 1) == 1) {
                d[i] = 1;
            }
            else d[i] = 0;
        }

        int tmp = 0;
        for (int i = 0; i < N; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 10; j++)
            {
                if(d[j] == 1 && f[i][j] == 1) cnt++;
            }
            tmp += p[i][cnt];
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}