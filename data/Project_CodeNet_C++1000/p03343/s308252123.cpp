#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod = 1e9+7;
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
const int N = 3e5+9;
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 2e9;
    for(int i = 1; i <= n; i++) {
        vector<vector<int>> splits;
        vector<int> split;
        for(int j = 1; j <= n; j++) {
            if(a[j] < a[i]) {
                splits.push_back(split);
                split.clear();
            } else {
                split.push_back(a[j]);
            }
        }
        if(split.empty() == false) {
            splits.push_back(split);
        }
        vector<int> cands;
        for(auto split: splits) {
            sort(split.begin(), split.end());
            int m = split.size(); 
            for(int j = 0; j < m-k+1; j++) {
                cands.push_back(split[j]);
            }
        }
        sort(cands.begin(), cands.end());
        int m = cands.size();
        if(m >= q) {
            ans = min(ans, cands[q-1]-cands[0]);
        }
    }
    cout << ans << "\n";









    return 0;
    
}