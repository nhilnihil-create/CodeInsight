#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> m;
    if(s[0] == '0')m.push_back(0);
    int cnt = 0;
    char c = s[0];
    rep(i, n){
        if(c != s[i]){
            m.push_back(cnt);
            cnt = 1;
            c = s[i];
            if(i == n - 1)m.push_back(cnt);
        }else{
            cnt++;
            if(i == n - 1)m.push_back(cnt);
        }
    }
    if(s[n-1] == '0')m.push_back(0);
    int l = m.size() / 2;
    if(l <= k)cout << n << endl;
    else{
        vector<int> sum(2 * l + 2, 0);
        sum[0] = 0;
        rep(i, 2*l+1)sum[i+1] = sum[i] + m[i];
        int ans = 0;
        rep(i, l - k + 1)ans = max(ans, sum[2*(i+k)+1]-sum[2*i]);
        cout << ans << endl;
    }
    
}