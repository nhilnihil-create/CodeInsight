#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K, A[100010], ans(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    while (1 + (K - 1) * ans < N)
        ans++;
    cout << ans << endl;
}