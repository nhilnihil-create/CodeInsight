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
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    std::vector<int> sum(N+1, 0);
    for (auto i=0; i<N; ++i)
    {
        sum[i+1] = sum[i];
        if (S[i] == 'C' && S[i-1] == 'A')
            sum[i+1]++;
    }

    for (auto i=0; i<Q; ++i)
    {
        int from, to;
        std::cin >> from >> to;
        std::cout << sum[to] - sum[from] << std::endl;
    }
}
