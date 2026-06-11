#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

int solve(std::string S)
{
    int ans_zero = 0, ans_one = 0, ans = 0;
    for(int i = 0; i < S.length(); i+=2)
    {
        if(S[i] != '0') ans_zero += 1;
        else ans_one += 1;
    }
    for(int i = 1; i < S.length(); i+=2)
    {
        if(S[i] != '1') ans_zero += 1;
        else ans_one += 1;
    }

    ans = std::min(ans_one, ans_zero);

    return ans;
}

int main()
{
    std::string S;
    std::cin >> S;
    
    int ans = solve(S);

    std::cout << ans << std::endl;
    return 0;
}