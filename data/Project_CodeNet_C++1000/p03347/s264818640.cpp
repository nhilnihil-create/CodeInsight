#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n;

int main() {
    cin >> n;
    vector<ll> avec(n, 0);
    for(int i = 0; i < n; ++i) cin >> avec[i];
    avec.emplace_back(-1);

    // 頭から確認していく
    bool flg = true;
    ll sum = 0;
    if(avec[0] != 0) flg = false;
    else {
        for(int i = 0; i < n; ++i) {
            if(avec[i] < avec[i+1]) {
                if(abs(avec[i]-avec[i+1]) == 1) {
                    // 正常
                }else flg = false;
            }else {
                sum += avec[i];
            }
        }
    }

    if(flg) cout << sum << endl;
    else cout << -1 << endl;
}