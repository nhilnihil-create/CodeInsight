#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using Pli = std::pair<long long, int>;

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector T(n, std::vector<long long>(0));

    for (int i = 0; i < n; i++)
    {
        int t;
        long long d;
        std::cin >> t >> d;
        T.at(t - 1).push_back(d);
    }
    std::vector Top(0, std::pair<long long, int>());
    for (int i = 0; i < n; i++)
    {
        if (!T.at(i).empty())
        {
            std::sort(T.at(i).begin(), T.at(i).end(), std::greater<long long>());
            Top.push_back({T.at(i).at(0), i});
        }
    }
    std::sort(Top.begin(), Top.end(), std::greater<Pli>());

    long long ans = 0, s = 0;
    //std::priority_queue<long long> sushi(std::greater<long long>(),std::vector<long long>());
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> sushi;
    int l = 0;
    for (long long j = 0; j < std::min(k, int(Top.size())); j++)
    {
        long long t = Top.at(j).first;
        int i = Top.at(j).second;

        s += t;
        if (l + j + 1 > k)
        {
            s -= sushi.top();
            sushi.pop();
            l -= 1;
        }
        for (int m = 1; m < int(T.at(i).size()); m++)
        {
            long long will = T.at(i).at(m);
            if (l + j + 1 >= k)
            {
                s += will;
                sushi.push(will);
                s -= sushi.top();
                sushi.pop();
            }
            else
            {
                s += will;
                l += 1;
                sushi.push(will);
            }
        }
        ans = std::max(ans, s + (j + 1) * (j + 1));
    }
    std::cout << ans << std::endl;
}
