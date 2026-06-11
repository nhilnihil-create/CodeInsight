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
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)
vector<int>w;
vector<int>s;
vector<int>v;
int32_t main()
{
    int n;
    cin >> n;
    w.resize(n);
    s.resize(n);
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> s[i] >> v[i];
    }
    vector<pair<int,int>> a;
    for(int i = 0; i < n; i++){
        a.push_back({w[i]+s[i], i});
    }
    sort(a.begin(),a.end());
    vector<int>dp(2e4+1,-2e18);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        auto x  = a[i].second;
        for(int j = 2e4; j >= 0; j--)
        {
            // первый не брать тек элемент
            // второй беру подложить вниз новый элемент
            // это возможно если прочность элемента x больше или равно чем вес j
            if (s[x] >= j && j + w[x] <= 2e4) {
                dp[j + w[x]] = max(dp[j + w[x]],dp[j] + v[x]);
            }
        }
    }
    int ans = -2e18;
    for(int i = 0 ; i < 2e4 + 1 ; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}