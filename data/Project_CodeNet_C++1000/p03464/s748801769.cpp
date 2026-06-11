#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

vector<ll> a;
ll N;

// index が条件を満たすかどうか
bool isOK(ll start, ll goal) {
    for(ll i = 0; i < N; i++) {
        start -= (start % a[i]);
    }
    if(start >= goal)
        return true;
    else
        return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll left = 1;         //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = longinf;  // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(right - left > 1) {
        ll mid = left + (right - left) / 2;
        if(isOK(mid, key))
            right = mid;
        else
            left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}
int main() {
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll under = binary_search(2);
    ll upper = binary_search(3);
    if(under >= upper)
        cout << -1 << "\n";
    else
        cout << under << " " << upper - 1 << "\n";
    return 0;
}