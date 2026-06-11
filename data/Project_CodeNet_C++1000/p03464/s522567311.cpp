#pragma region Macros
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
#pragma endregion

void solve(){
    int k;
    cin >> k;
    vector<ll> a(k);
    for (int i=0; i<k; i++) {
        cin >> a.at(i);
    }
    ll maxi = 2, mini = 2;
    for (auto iter=a.rbegin(); iter!=a.rend(); iter++) {
        ll tmp = *iter;
        ll cnt = maxi / tmp - mini / tmp + (mini%tmp == 0);
        if (cnt == 0) {
            cout << -1 << "\n";
            return;
        } else {
            if (mini%tmp == 0) {
                maxi = (maxi/tmp) * tmp + tmp - 1;
            } else {
                mini = (mini/tmp + 1) * tmp;
                maxi = (maxi/tmp) * tmp + tmp - 1;
            }
        }
    }

    cout << mini << " " << maxi << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
