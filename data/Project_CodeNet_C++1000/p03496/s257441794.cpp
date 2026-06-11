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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    int maxi = -1;
    int ind = -1;
    for (int i=0; i<n; i++) {
        if (chmax(maxi, abs(a.at(i)))) ind = i;
    }
    maxi = a.at(ind);
    cout << 2*n-1 << endl;
    for (int i=1; i<n+1; i++) {
        cout << ind+1 << " " << i << "\n";
    }
    if (maxi > 0) {
        for (int i=2; i<n+1; i++) {
            cout << i-1 << " " << i << "\n";
        }
    } else {
        for (int i=n; i>1; i--) {
            cout << i << " " << i-1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
