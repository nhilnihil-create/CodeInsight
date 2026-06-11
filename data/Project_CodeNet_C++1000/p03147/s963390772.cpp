#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N;
    cin >> N;
    vector<int> h(N);
    REP(i, N) cin >> h[i];
    int ans = 0;
    for (int cur = 1; cur <= 100; ++cur)
    {  
        int numgroup = 0;
        bool chain = false;
        bool ok = false;
        REP(i, N)
        {
            if (h[i] >= cur)
            {
                ok = true;
                if (!chain)
                {
                    chain = true;
                    ++numgroup;
                }
            }
            else
            {
                if (chain)
                {
                    chain = false;
                }
            }
        }
        if (!ok) break;
        ans += numgroup;
    }
    cout << ans << endl;
    return 0;
}
