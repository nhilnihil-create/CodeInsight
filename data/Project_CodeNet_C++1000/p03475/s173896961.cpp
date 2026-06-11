// https://atcoder.jp/contests/abc084/tasks/abc084_c
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int N;
    cin >> N;
    vector<int> C(N - 1), S(N - 1), F(N - 1);
    for (int i = 0; i < N - 1; ++i) cin >> C[i] >> S[i] >> F[i];
    if (N == 1)
    {
        cout << S[0] + C[0] << endl;
        return 0;
    }
    vector<int> res(N, 0);
    res[N-1] = 0;
    
    res[N-2] = S[N-2] + C[N-2];
    for (int i = 0; i < N - 2; ++i)
    {
        int t = S[i] + C[i];
        for (int in = i + 1; in < N - 1; ++in)
        {
            if (t > 0 && t <= S[in])
            {
                t = S[in] + C[in];
                continue;
            }
            int m = 1;
            while(true)
            {
                if (t > S[in] + F[in] * (m - 1) && t <= S[in] + F[in] * m)
                {
                    t = S[in] + F[in] * m + C[in];
                    break;
                }
                else ++m;
            }
        }
        res[i] = t;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << res[i] << endl;
    }

    return 0;
}
