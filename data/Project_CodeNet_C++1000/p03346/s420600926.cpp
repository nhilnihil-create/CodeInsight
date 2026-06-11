#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n),dp(n+1,0);
    for(int i=0;i<n;i++) cin >> v[i];
    set<int> s;
    for(int i=0;i<n;i++) {
        auto it = s.find(v[i]-1);
        if(it==s.end()) {
            dp[v[i]]=1;
        } else {
            dp[v[i]] = dp[v[i]-1]+1;
        }
        s.insert(v[i]);
    }

    int x = *max_element(dp.begin(),dp.end());
    cout << n-x << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}