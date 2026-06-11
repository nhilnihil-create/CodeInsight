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
const ll INF = 1 << 29;
const ll MOD = 1e9 + 7;

int main()
{
    int N;
    ll Z, W;
    std::cin >> N >> Z >> W;

    std::vector<ll> A(N);
    for (auto i=0; i<N; ++i)
        std::cin >> A[i];

    if (N == 1)
        std::cout << std::abs(A[N-1] - W) << std::endl;
    else
        std::cout << std::max(std::abs(A[N-1] - W), std::abs(A[N-2] - A[N - 1])) << std::endl;
}
