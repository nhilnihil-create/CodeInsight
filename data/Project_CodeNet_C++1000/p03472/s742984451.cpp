#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;
const double PI = 3.14159265359;

int main()
{
    int N, H; cin >> N >> H;
    vector<int> as(N), bs(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> as[i] >> bs[i];
    }
    int maxA = *max_element(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int ans = 0;
    while (H > 0)
    {
        if (bs.empty() || bs.back() < maxA)
        {
            ans += (H + maxA - 1) / maxA;
            break;
        }
        else
        {
            H -= bs.back();
            bs.pop_back();
            ++ans;
        }
    }
    cout << ans << endl;
}
