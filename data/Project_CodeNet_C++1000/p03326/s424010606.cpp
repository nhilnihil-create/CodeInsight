#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

long compute(vector<array<long, 3>> data, int m, bool max_x, bool max_y, bool max_z)
{
    auto sum = [&](const array<long, 3> &d) {
                   return
                       (d[0] * (max_x ? 1 : -1)) +
                       (d[1] * (max_y ? 1 : -1)) +
                       (d[2] * (max_z ? 1 : -1));
               };
    sort(data.begin(), data.end(),
         [&](const array<long, 3> &d1, const array<long, 3> &d2) { return sum(d1) > sum(d2); });

    long out(0);
    for (int i = 0; i < m; ++i)
        out += sum(data[i]);

    return out;
}


int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<array<long, 3>> data(n);
    for (int i = 0; i < n; ++i)
    {
        auto &d = data[i];
        cin >> d[0] >> d[1] >> d[2];
    }

    long out(0);
    for (auto max_x : { true, false })
    {
        for (auto max_y : { true, false })
        {
            for (auto max_z : { true, false })
            {
                auto v = compute(data, m, max_x, max_y, max_z);
                out = max(v, out);
            }
        }
    }
    
    cout << out << endl;
}
