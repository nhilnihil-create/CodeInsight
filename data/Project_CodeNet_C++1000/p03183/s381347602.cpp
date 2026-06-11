/*
解説AC.

*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> W(N), S(N), V(N);
    rep(i, 0, N) {
        cin >> W[i] >> S[i] >> V[i];
    }
    vector<int> idx(N);
    rep(i, 0, N) {
        idx[i] = i;
    }
    // sort(all(idx), [&](int i1, int i2) {
    //     return S[i1] + W[i1] < S[i2] + W[i2];
    // });
    sort(all(idx), [&](int i1, int i2) {
        return min(S[i1], S[i2] - W[i1]) > min(S[i2], S[i1] - W[i2]);
    });
    ll max_val = *max_element(all(S)) + *max_element(all(W));
    vector<vector<ll>> dp(N + 1, vector<ll>(max_val + 1, 0));
    rep(i, 1, N + 1) rep(j, 0, max_val + 1) {
        dp[i][j] = dp[i - 1][j];
        if (j - W[idx[i - 1]] >= 0 && j - W[idx[i - 1]] <= S[idx[i - 1]]) {
            chmax(dp[i][j], dp[i - 1][j - W[idx[i - 1]]] + V[idx[i - 1]]);
        }
    }
    ll ans = 0;
    rep(i, 0, max_val + 1) {
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}