#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    vector<int> Ds(N); for (auto &Di : Ds) cin >> Di;
    sort(Ds.begin(), Ds.end());
    bool sign = true;
    vector<int> hours(N);
    for (int i = 0; i < N; ++i)
    {
        if (Ds[i] == 0)
        {
            hours[i] = 0;
        }
        else
        {
            hours[i] = sign ? Ds[i] : 24 - Ds[i];
        }
        sign = sign ? false : true;
    }
    hours.push_back(0);
    sort(hours.begin(), hours.end());
    int ans = 24;
    for (int i = 0; i < N + 1; ++i)
    {
        int diff = hours[(i + 1) % (N + 1)] - hours[i];
        if (diff < 0) diff = 24 + diff;
        ans = min(ans, diff);
    }
    cout << ans << endl;
}
