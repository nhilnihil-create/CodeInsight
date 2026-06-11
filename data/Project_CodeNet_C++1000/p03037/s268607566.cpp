#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

int solve(int& N, int& M)
{
    int L = 0, R = INT_MAX;
    
    for(int i=0; i<M; i++)
    {
        int Lt, Rt;
        std::cin >> Lt >> Rt;
        L = std::max(Lt, L);
        R = std::min(Rt, R);
    }

    int ans = R - L + 1;

    if (ans > 0) return ans;
    else return 0;
}

int main()
{
    int N, M; std::cin >> N >> M;
    int L = 0, R = INT_MAX;

    int ans = solve(N, M);
    
    std::cout << ans << std::endl;
    return 0;
}