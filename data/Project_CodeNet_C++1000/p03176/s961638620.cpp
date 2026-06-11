#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 5;
int n, h[maxn], a[maxn];

int32_t main(){
    cin >> n;
    h[0] = 0; a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> dp;
    for(int i = n; i >= 0; i--){
        auto it = dp.upper_bound(h[i]);
        int sum = a[i];
        if(it != dp.end())
            sum += it -> second;
        dp[h[i]] = sum;
        it = dp.find(h[i]);
        while(it != dp.begin() && prev(it) -> second <= sum)
            it = dp.erase(prev(it));
    }
    cout << dp[0] << "\n";
    return 0;
}