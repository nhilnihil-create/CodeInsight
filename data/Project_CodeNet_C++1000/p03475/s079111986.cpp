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
    vector<int> res(N);
    for (int i = 0; i < N; ++i)
    {
        int t = 0;
        for (int in = i; in < N - 1; ++in)
        {
            if (t < S[in]) t = S[in] + C[in];
            else if (t % F[in] == 0) t += C[in];
            else t = t + F[in] - t % F[in] + C[in];
        }
        res[i] = t;
    }

    for (int i = 0; i < N; ++i)
    {
        cout << res[i] << endl;
    }

    return 0;
}
