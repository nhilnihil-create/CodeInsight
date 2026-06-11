typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    string s;
    std::cin >> s;
    ll q;
    std::cin >> q;
    
    vector<ll> dp(n+1,0);
    vector<ll> cc(n+1,0),cm(n+1,0);
    vector<ll> dd;
    ll mc = 0;
    for (int i = 0; i < n; i++) {
        cc[i+1] = cc[i];
        cm[i+1] = cm[i];
        dp[i+1] = dp[i];
        if(s[i]=='C'){
            cc[i+1]++;
            dp[i+1]+=mc;
        }else if(s[i]=='M'){
            cm[i+1]++;
            mc++;
        }else if(s[i]=='D'){
            dd.push_back(i);
        }
    }

    for (int iiii = 0; iiii < q; iiii++) {
        ll k;
        std::cin >> k;
        
        ll ans = 0;
        
        for (auto e : dd) {
            ans += dp[min(n,e+k)]-dp[e+1]-cm[e+1]*(cc[min(n,e+k)]-cc[e+1]);
        }
        std::cout << ans << std::endl;
    }
}

