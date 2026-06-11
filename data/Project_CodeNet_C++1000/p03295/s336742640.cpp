#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, 0, M) {
        cin >> A[i] >> B[i];
    }
    vector<P> interval;
    rep(i, 0, M) {
        interval.emplace_back(B[i], A[i]);
    }
    sort(all(interval));
    int prev = -1;
    int ans = 0;
    for (auto& i : interval) {
        if (i.second > prev) {
            ++ans;
            prev = i.first - 1;
        }
    }
    cout << ans << endl;
    return 0;
}