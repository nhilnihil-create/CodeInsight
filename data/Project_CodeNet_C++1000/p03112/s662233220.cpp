#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

const ll INF = 1LL << 60;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> S(A);
    for (auto& s : S) {
        cin >> s;
    }
    vector<ll> T(B);
    for (auto& t : T) {
        cin >> t;
    }
    ll X;
    rep(_, 0, Q) {
        cin >> X;
        int idx1 = lower_bound(all(S), X) - S.begin();
        int idx2 = lower_bound(all(T), X) - T.begin();
        vector<ll> candidate1, candidate2;
        rep(i, -1, 2) {
            if (idx1 + i >= 0 && idx1 + i < A) {
                candidate1.push_back(idx1 + i);
            }
            if (idx2 + i >= 0 && idx2 + i < B) {
                candidate2.push_back(idx2 + i);
            }
        }
        ll ans = INF;
        for (auto& i : candidate1) for (auto& j : candidate2) {
            chmin(ans, abs(X - S[i]) + abs(S[i] - T[j]));
            chmin(ans, abs(X - T[j]) + abs(S[i] - T[j]));
        }
        cout << ans << endl;
    }
    return 0;
}