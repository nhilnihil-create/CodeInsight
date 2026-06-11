#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 二分探索ライブラリを書いたので
// 0-indexed

int N, Q;
string S;
vector<char> t, d;

// ゴーレムが左に落ちるならtrue
bool is_fallen_left(ll id) {
    for (int i = 0; i < Q; ++i) {
        if (t[i] == S[id]) {
            if (d[i] == 'L') id--;
            else id++;
        }
        if (id < 0) return true;
        if (id >= N) return false;
    }
    return false;
}

// ゴーレムが右に落ちるならtrue
bool is_fallen_right(ll id) {
    for (int i = 0; i < Q; ++i) {
        if (t[i] == S[id]) {
            if (d[i] == 'L') id--;
            else id++;
        }
        if (id < 0) return false;
        if (id >= N) return true;
    }
    return false;
}

// 開区間と判定関数を引数にして条件を満たす境界値を返す
ll BiSearch(ll ok, ll ng, function<bool(ll)> C){
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (C(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin >> N >> Q >> S;
    t.resize(Q); d.reserve(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> t[i] >> d[i];
    }

    ll lb = BiSearch(-1, N, is_fallen_left);
    ll rb = BiSearch(N, -1, is_fallen_right);
    ll ans = rb - lb - 1;
    if (ans < 0) ans = 0;
    cout << ans << "\n";
    return 0;
}