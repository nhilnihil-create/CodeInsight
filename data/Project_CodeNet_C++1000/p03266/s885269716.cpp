#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

ll exp(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * exp(a, b - 1);
}

int main()
{
    int N, K;
    cin >> N >> K;
    if (K == 1)
    {
        cout << exp(N, 3) << endl;
    }
    else if (K % 2 == 0)
    {
        int num = 0;
        rep(1, i, N + 1)
        {
            if (i % K == K / 2)
            {
                num++;
            }
        }
        cout << exp(N / K, 3) + exp(num, 3) << endl;
    }
    else
    {
        cout << exp(N / K, 3) << endl;
    }
}
