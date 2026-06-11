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
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    ll sum = 0;
    int right = 0;
    ll ans = 0;
    for (int left=0; left<N; left++) {
        while (right < N && sum + A.at(right) == (sum ^ A.at(right))) {
            sum += A.at(right);
            right++;
        }
        ans += right - left;
        if (left == right) {
            right++;
        } else {
            sum -= A.at(left);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
