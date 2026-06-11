#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    ll n;
    cin >> n;
    string s;
    vector<ll> num(5,0);
    rep1(i, n){
        cin >> s;
        if (s[0]=='M') num[0]++;
        if (s[0]=='A') num[1]++;
        if (s[0]=='R') num[2]++;
        if (s[0]=='C') num[3]++;
        if (s[0]=='H') num[4]++;
    }
    ll ans = 0;
    int bit = (1<<3)-1;
    for (;bit < (1<<5); bit = next_combination(bit)) {
        ll cnt=1;
        for (int i = 0; i < 5; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                cnt *= num[i];
            }
        }
        ans += cnt;
    }
    cout << ans << endl;
}