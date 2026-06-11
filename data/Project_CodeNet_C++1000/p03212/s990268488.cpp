#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
ll cnt = 0;
void dfs(ll now,ll n) {
    if (now > n){
        return;
    } else {
        string x = to_string(now);
        if(count(x.begin(),x.end(),'3')&&count(x.begin(),x.end(),'5')&&count(x.begin(),x.end(),'7')){
            cnt++;
        }
        for (ll i = 3; i <= 7; i += 2) {
            dfs(now * 10 + i, n);
        }
    }
}
int main() {
    ll n;
    cin >> n;
    dfs(0LL, n);


    cout << cnt << endl;
}
