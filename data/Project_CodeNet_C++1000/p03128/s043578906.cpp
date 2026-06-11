#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    rep(i, m)cin >> a[i];
    rep(i, 10){
        bool v = false;
        rep(j, m)if(i == a[j])v = true;
        if(!v)b[i] = -1;
    }
    vector<string> dp(n+1, "");
    for(int i = 0; i <= n; i++){
        for(int j = 9; j > 0; j--){
            if(b[j] == -1)continue;
            if(i + b[j] > n)continue;
            if(i > 0 && dp[i].size() == 0)continue;
            if(dp[i+b[j]].size() < dp[i].size() + 1){
                char c = '0' + j;
                dp[i+b[j]] = dp[i] + c;
            }else if(dp[i+b[j]].size() == dp[i].size() + 1){
                char c = '0' + j;
                string s = dp[i] + c;
                vector<int> cnt1(10), cnt2(10);
                rep(k, s.size()){
                    cnt1[s[k]-'0']++;
                    cnt2[dp[i+b[j]][k]-'0']++;
                }
                for(int k = 9; k > 0; k--){
                    if(cnt1[k] > cnt2[k]){
                        dp[i+b[j]] = s;
                        break;
                    }else if(cnt1[k] < cnt2[k])break;
                }
            }
        }
    }
    sort(dp[n].begin(), dp[n].end(), greater<char>());
    cout << dp[n] << endl;
}