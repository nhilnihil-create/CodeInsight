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
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    REP(i, N) cin >> x[i];
    vector<int> plusvec, minusvec;
    int zeros = 0;
    REP(i, N)
    {
        if (x[i] > 0) plusvec.push_back(x[i]);
        else if (x[i] < 0) minusvec.push_back(-x[i]);
        else ++zeros;
    }
    K -= zeros;
    if (K == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if(plusvec.empty() && !minusvec.empty())
    {
        sort(minusvec.begin(), minusvec.end());
        cout << minusvec[K - 1] << endl;
        return 0;
    }
    else if (!plusvec.empty() && minusvec.empty())
    {
        sort(plusvec.begin(), plusvec.end());
        cout << plusvec[K - 1] << endl;
        return 0;
    }

    sort(plusvec.begin(), plusvec.end());
    sort(minusvec.begin(), minusvec.end());
    
    ll ans = numeric_limits<ll>::max();
    int rmx = min(K, static_cast<int>(plusvec.size()));
    for (int ridx = rmx - 1; ridx >= 0; --ridx)
    {
        ll t = plusvec[ridx];
        int lidx = K - 2 - ridx;

        if (lidx < 0)
        {
            ans = min(ans, t);
        }
        else if (lidx > static_cast<int>(minusvec.size()) - 1)
            break;
        else
        {
            t += 2 * minusvec[lidx];
            ans = min(ans, t);
        }
    }

    int lmx = min(K, static_cast<int>(minusvec.size()));
    for (int lidx = lmx - 1; lidx >= 0; --lidx)
    {
        ll t = minusvec[lidx];
        int ridx = K - 2 - lidx;
        if (ridx < 0)
        {
            ans = min(ans, t);
        }
        else if (ridx > static_cast<int>(plusvec.size()) - 1)
            break;
        else
        {
            t += 2 * plusvec[ridx];
            ans = min(ans, t);
        }
    }

    cout << ans << endl;
    return 0;
}
