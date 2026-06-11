#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, m;
vector<vector<lli>> v(100100);
vector<lli> dp(100100);
vector<bool> seen(100100);

lli f(lli x){
    if(seen[x]) return dp[x];
    seen[x] = true;
    lli mx = 0;
    for(auto to : v[x]){
        mx = max(mx, f(to)+1);
    }
    return dp[x] = mx;
}

int main(void){
    cin >> n >> m;
    rep(i, m){
        lli a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
    }
    lli ans = 0;
    rep(i, n){
        ans = max(ans, f(i));
    }
    cout << ans << endl;
    return 0;
}
