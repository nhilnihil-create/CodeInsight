#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, K, x, cnt0 = 0;
    cin >> N >> K;
    vector<ll> Plus(1), Minus(1);
    rep(i,N) {
        cin >> x;
        if (x == 0) ++cnt0;
        else if (x > 0) Plus.push_back(x);
        else Minus.push_back(-x);
    }
    sort(Plus.begin(), Plus.end());
    sort(Minus.begin(), Minus.end());
    
    ll ans = INFINITY;
    if (cnt0 == K) ans = 0;
    int i = 0;
    while (i < K - cnt0) {
        if (i < Minus.size() && K - cnt0 - i < Plus.size()) {
            ll tmp = Minus.at(i) * 2 + Plus.at(K - cnt0 - i);
            ans = min(ans, tmp);
        }
        ++i;
    }
    i = 0;
    while (i < K - cnt0) {
        if (i < Plus.size() && K - cnt0 - i < Minus.size()) {
            ll tmp = Plus.at(i) * 2 + Minus.at(K - cnt0 - i);
            ans = min(ans, tmp);
        }
        ++i;
    }
    cout << ans << endl;
}
