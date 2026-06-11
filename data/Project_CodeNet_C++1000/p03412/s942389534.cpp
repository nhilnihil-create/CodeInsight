#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int64_t> as(n), bs(n);

    for (auto& a : as)
    {
        cin >> a;
    }
    for (auto& b : bs)
    {
        cin >> b;
    }

    // ai + bj の k 桁目に何個 1 が xor されるか
    array<int64_t, 32> counter;
    fill(counter.begin(), counter.end(), 0);

    // 桁上がり考えない
    {
        array<int64_t, 32> a0, a1, b0, b1;
        fill(a0.begin(), a0.end(), 0);
        fill(a1.begin(), a1.end(), 0);
        fill(b0.begin(), b0.end(), 0);
        fill(b1.begin(), b1.end(), 0);

        for (auto a : as)
        {
            for (int i = 0; i < 32; i++)
            {
                if (a & (1ll << i))
                {
                    a1[i]++;
                }
                else
                {
                    a0[i]++;
                }
            }
        }
        for (auto b : bs)
        {
            for (int i = 0; i < 32; i++)
            {
                if (b & (1ll << i))
                {
                    b1[i]++;
                }
                else
                {
                    b0[i]++;
                }
            }
        }
        for (int i = 0; i < 32; i++)
        {
            counter[i] += a0[i] * b1[i] + a1[i] * b0[i];
        }
    }

    // 桁上がり

    for (int i = 0; i < 32; i++)
    {
        const int64_t mask = (1ll << i) - 1;

        vector<int64_t> bs_under(n);
        for (int j = 0; j < n; j++)
        {
            bs_under[j] = bs[j] & mask;
        }
        sort(bs_under.begin(), bs_under.end());

        for (auto a : as)
        {
            const auto a_mask = a & mask;
            auto first_point = lower_bound(bs_under.begin(), bs_under.end(), (1ll << i) - a_mask);

            counter[i] += distance(first_point, bs_under.end());
        }
    }

    int64_t ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        ans *= 2;
        ans += counter[i] % 2;
    }
    cout << ans << endl;
}
