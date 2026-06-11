#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const ll MOD = 1E+9 + 7;

int main() {
    ll N;
    cin >> N;

    string S;
    cin >> S;

    map<char, int> mp;
    rep(i, N) mp[S[i]]++;

    ll ans = 1;
    for (auto& x: mp) {
        ans *= x.second + 1;
        ans %= MOD;        
    }
    ans--;

    cout << ans << endl;

    return 0;
}