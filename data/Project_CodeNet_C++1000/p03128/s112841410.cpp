#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> a(m);
    
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    int p[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    struct R {
        R() : len(-1) {
            fill(c.begin(), c.end(), 0);
        }
        
        int len;
        std::array<int, 9> c;   
    
        bool operator<(const R& rhs) const {
            if (len == -1) {
                return true;
            } else if (rhs.len == -1) {
                return false;
            } else if (len == rhs.len) {
                return c < rhs.c;
            } else {
                return len < rhs.len;
            }
        }
    };
    
    vector<R> dp(n + 1);
    
    dp[0].len = 0;
    
    for (int i = 0; i < n; i++) {
        if (dp[i].len == -1) {
            continue;
        }
        
        for (int k : a) {
            int s = i + p[k];
            
            if (s <= n) {
                R st = dp[i];
                st.len++;
                
                st.c[9 - k]++;
                
                dp[s] = max(dp[s], st);
            }
        }
    }
    
    string ans;
    
    for (int i = 0; i < 9; i++) {
        ans += string(dp[n].c[i], '9' - i);
    }
    
    cout << ans << endl;
}
