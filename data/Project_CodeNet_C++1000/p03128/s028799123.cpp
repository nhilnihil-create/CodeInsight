#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

using namespace std;
typedef long long ll;


int INF = 2e9;

int main(int argc, const char * argv[]) {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+1, -INF); // dp[i] : ちょうどi本のマッチ棒を使うときの最大桁数
    
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    
    vector<int> table2num ={-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    for (int i = 1; i < n+1; ++i)
    {
        rep(j, m)
        {
            int idx = i - table2num[a[j]];
            if (idx < 0) continue;
            else
            {
                if (idx == 0)
                {
                    dp[i] = max(dp[i], 1);
                }
                else
                {
                    dp[i] = max(dp[i], dp[idx] + 1);
                }
            }
            
        }
    }
    
    dp[0] = 0;
    
    
    
    sort(a.begin(), a.end(), std::greater<int>());
    int match_idx = n;
    for (int i = dp[n]; i>0; --i)
    {
        for (int j : a)
        {
            if (match_idx - table2num[j] < 0) continue;
            if (dp[match_idx - table2num[j]] == dp[match_idx] - 1)
            {
                match_idx -= table2num[j];
                cout << j;
                break;
            }
        }
    }
    
    cout << endl;
    
    
    
    
    return 0;
}