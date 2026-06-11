#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(a + b > n + 1 || a * b < n) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans;
    ll s = n - a;
    ll cur = n;
    rep(i, 0, a){
        ll num = min(b-1, s) + 1;
        s -= num-1;
        rep(j, 0, num) ans.push_back(cur - (num-1) + j);
        cur -= num;
    }
    reverse(ans.begin(), ans.end());
    rep(i, 0, n) cout << ans[i] << (i == n-1 ? "\n" : " ");
    return 0;
}