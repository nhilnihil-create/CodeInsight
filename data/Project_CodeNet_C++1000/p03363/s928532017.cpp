#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;


int main()
{
    ll N;
    std::cin >> N;
    std::vector<ll> S(N + 1, 0);
    for (auto i=0; i<N; ++i)
    {
        ll a;
        std::cin >> a;
        S[i+1] = S[i] + a;
    }

    std::sort(S.begin(), S.end());

    ll result = 0;
    ll candidates = 1;
    for (auto i=1; i<N+1; ++i)
    {
        if (S[i] - S[i-1] == 0)
            candidates++;

        if (S[i] != S[i - 1] || i == N)
        {
            // 候補から2つ選ぶので xC2 = x * (x - 1) / 2
            result += candidates * (candidates - 1) / 2;
            candidates = 1;
        }
    }

    std::cout << result << std::endl;
}
