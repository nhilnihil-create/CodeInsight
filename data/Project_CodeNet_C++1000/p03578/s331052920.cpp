#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    ll n, m;
    map<ll, ll> mp1, mp2;
    cin >> n;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        mp1[a]++;
    }
    cin >> m;
    rep(i, 0, m) {
        ll a;
        cin >> a;
        mp2[a]++;
    }
    bool f = true;
    for(auto p : mp2) {
        if(p.second > mp1[p.first]) f = false;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}