/* 

*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <utility>
#include <bitset>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define LSOne(S) (S & (-S))
#define EPS 1e-9
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pd;
typedef tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

inline bool IsOn(int& mask, int& b)
{
    return (mask & (1 << b));
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // BEFORE SUBMIT DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    vector<vector<int>> score(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> score[i][j];
        }
    }    

    int limit = (1 << n);
    vector<ll> sum(limit);

    for(int mask = 0; mask < limit; ++mask)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = j+1; k < n; ++k)
            {
                if(IsOn(mask, j) && IsOn(mask, k))
                {
                    sum[mask] += score[j][k];
                }
            }
        }
    }

    vector<ll> dp(limit); // Max score if '1' bit in mask is already part of a group
    for(int mask = 0; mask < limit; ++mask)
    {
        for(int submask = mask; ; submask = (submask-1) & mask)
        {
            dp[mask] = max(dp[mask], dp[submask] + sum[mask ^ submask]);
            if(submask == 0) break;
        }
    }
    cout << dp[limit-1] << "\n";
    return 0; 
}
