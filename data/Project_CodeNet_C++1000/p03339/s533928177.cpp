#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

// 最大公約数
ll gcd(ll a, ll b)
{
   if (a%b == 0) {
       return(b);
   } else {
       return(gcd(b, a%b));
   }
}

// 最小公倍数
ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    Vl w(n, 0), e(n, 0);
    rep(i, 1, n) {
        w[i] = w[i-1];
        if(s[i-1] == 'W') w[i]++;
    }
    for(int i = n-2; i >= 0; i--){
        e[i] = e[i+1];
        if(s[i+1] == 'E') e[i]++;
    }
    // rep(i, 0, n) cout << w[i];
    // cout << endl;
    // rep(i, 0, n) cout << e[i];
    // cout << endl;
    Vl v(n, 0);
    rep(i, 0, n) v[i] = w[i] + e[i];
    ll ans = 1001001001;
    rep(i, 0, n) ans = min(ans, v[i]);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}