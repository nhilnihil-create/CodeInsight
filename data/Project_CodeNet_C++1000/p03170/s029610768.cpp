#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<bool> dp(110000,0);

    for(int i = 0; i <= k; i++){
        for (int j = 0; j < n; j++){
            if(i-a[j] >= 0){
                bool s = dp[i];
                bool t = !dp[i-a[j]];
                s |= t;
                dp[i] = s;
            }
        }
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;

return 0;
}