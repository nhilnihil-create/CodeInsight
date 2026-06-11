#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int V[N], C[N];
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        int XY = 0;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
            {
                XY += V[i] - C[i];
            }
        }
        ans = max(ans, XY);
    }
    cout << ans << endl;
}
