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
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    if (A[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    ll prev = A.back();
    rrep(i, N, 0) {
        if (A[i] >= prev) {
            ans += A[i];
        }
        else if (prev - A[i] >= 2) {
            cout << -1 << endl;
            return 0;
        }
        prev = A[i];
    }
    cout << ans << endl;
    return 0;
}