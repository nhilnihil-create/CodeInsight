#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for (auto& h : H) {
        cin >> h;
    }
    sort(all(H));
    int ans = 1 << 30;
    rep(i, K - 1, N) {
        chmin(ans, H[i] - H[i - K + 1]);
    }
    cout << ans << endl;
    return 0;
}