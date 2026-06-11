#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> as(n), bs(n);

    int64_t a_sum = 0, b_sum = 0;

    for (auto& a : as)
    {
        cin >> a;
        a_sum += a;
    }
    for (auto& b : bs)
    {
        cin >> b;
        b_sum += b;
    }

    const auto lim = b_sum - a_sum;
    int64_t a_move = 0, b_move = 0;
    for (int i = 0; i < n; i++)
    {
        if (as[i] > bs[i])
        {
            b_move += as[i] - bs[i];
        }
        else
        {
            a_move += (bs[i] - as[i] + 1) / 2;
        }
    }
    cout << (max(a_move, b_move) <= lim ? "Yes" : "No") << endl;
}
