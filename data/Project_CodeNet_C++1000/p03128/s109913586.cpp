#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

// a >= b ?
bool comp(string a, string b){
    if(b == "-") return true;
    if(a == "-") return false;
    if(a.size() > b.size()) return true;
    if(a.size() < b.size()) return false;
    rep(i, 0, a.size()){
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return true;
}

ll r[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<string> dp(n+1000, "-");
    rep(i, 0, m) cin >> a[i];
    dp[0] = "";
    rep(i, 0, n+1){
        if(dp[i] == "-") continue;
        for(auto e : a){
            if(!comp(dp[i+r[e]], dp[i] + (char)('0' + e))) dp[i+r[e]] = dp[i] + (char)('0' + e);
        }
    }
    cout << dp[n] << endl;
    return 0;
}