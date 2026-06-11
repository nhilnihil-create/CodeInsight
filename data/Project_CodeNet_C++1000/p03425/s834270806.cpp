#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S.at(i);
    string T = "MARCH";

    map<char, ll> mp;
    rep(i,N) {
        rep(j,5) {
            if (S.at(i).at(0) == T.at(j)) ++mp[T.at(j)];
        }
    }
    ll ans = 0;
    if (mp.size() >= 3) {
        for (int bit = 0; bit < (1<<mp.size()); bit++) {
            bitset<5> s(bit);
            if (s.count() == 3) {
                ll add = 1;
                for (int i = 0; i < mp.size(); i++) {
                    if (bit & (1<<i)) {
                        add *= mp[T.at(i)];
                    }
                }
                ans += add;
            }
        }
    }
    cout << ans << endl;
}
