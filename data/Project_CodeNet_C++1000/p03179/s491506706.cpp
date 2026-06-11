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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int MOD = 1e9+7;

int ModAdd(int& x, int y)
{
    x += y;
    if(x >= MOD) x -= MOD;
    return x;
}

int ModSub(int x, int y)
{
    x -= y;
    if(x < 0) x += MOD;
    return x;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); // FOR QUERY PROBLEM DON'T FORGET TO UNCOMMENT THIS
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<int>> dp(n, vector<int>(n)); // answer for prefix length i, last number has j smaller element than it
    vector<vector<int>> psum(n, vector<int>(n));
    dp[0][0] = psum[0][0] = 1;

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(str[i-1] == '<')
            {
                if(j > 0) ModAdd(dp[i][j], psum[i-1][j-1]);
            }
            else
            {
                ModAdd(dp[i][j], ModSub(psum[i-1][i-1], (j-1 >= 0 ) ? psum[i-1][j-1] : 0));
            }   
        }

        for(int j = 0; j <= i; ++j)
        {
            psum[i][j] = dp[i][j];
            if(j > 0) ModAdd(psum[i][j], psum[i][j-1]);
        }
    }
    cout << psum[n-1][n-1] << "\n";
    return 0;  
}