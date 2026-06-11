#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    n = (1 << n);

    int maxi = 18;
    int maxj = (1 << 18);

    int a[n + 5];
    std::multiset<int> seti[maxj + 5] = {};
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        seti[i].insert(a[i]);
    }

    for (int i = 0; i < maxi; ++i)
    {
        for (int j = 0; j < maxj; ++j)
        {
            if ((j & (1 << i)))
            {
                int low = (j ^ (1 << i));
                for (auto it : seti[low])
                    seti[j].insert(it);

                while (seti[j].size() > 2)
                    seti[j].erase(seti[j].begin());
            }
        }
    }

    long long int maxans = 0;
    for (int k = 1; k < n; ++k)
    {
        auto it = seti[k].begin();
        long long int sum = *it;
        ++it;
        sum += *it;
        maxans = std::max(maxans, sum);
        std::cout << maxans << "\n";
    }
}
