#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int main()
{
    int64_t N, K, tmp, ans = 0;
    cin >> N >> K;
    if (K == 0)
        cout << N * N;
    else
    {
        for (int b = K + 1; b <= N; b++)
        {
            ans += (N / b) * (b - K);
            tmp = N % b;
            if (tmp >= K)
                ans += tmp - K + 1;
        }
        cout << ans;
    }
}