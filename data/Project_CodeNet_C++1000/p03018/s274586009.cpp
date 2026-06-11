#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s.push_back('?');
    vector<int> dp(n+1), occ;
    occ.push_back(n);
    long long ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'A') {
            ans += dp[occ.back()];
        }
        else {
            occ.push_back(i);
            if(s[occ.back()] == 'B' && s[occ[occ.size()-2]] == 'C' && occ.back()+1 == occ[occ.size()-2]) {
                dp[i] = 1+dp[occ[occ.size()-3]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

