#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
#include <cctype>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)

const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    // dp по маске у нас 10110111110
    //                     10010110100
    //                  dp[00100001010]
    int n;
    cin >> n;
    vector<vector<int>> a(n + 3, vector<int> (n + 3, 0));
    forn(i, n){
        forn(j,n){
            cin >> a[i][j];
        }
    }
    vector<int>score((1 << n) + 33, 0);
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++){
            if((1 << i) & mask) {
                for (int j = 0; j < i; j++) {
                    if((1 << j) & mask)
                        score[mask] += a[i][j];
                }
            }
        }
    }
    vector<int> dp((1<< n) +33, 0);
    int ans = 0;
    for(int mask =  1; mask < (1 << n); mask++){
        for (int submask = mask; submask > 0; submask--, submask &= mask) {
            dp[mask] = max(dp[mask], score[submask] + dp[mask ^ submask]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
