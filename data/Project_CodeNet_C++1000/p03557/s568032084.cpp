#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

template <typename T>
ll nCr(T n, T r) {
ll ans = 1;
    for (int i = n; i > n - r; --i) {
            ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans/i;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int>B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];
    vector<int>C(N);
    for (int i = 0; i < N; ++i) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    ll res = 0;
    for (auto&& b : B) {
        // lower_boundのイテレータから先頭のイテレータを引くと，あるkeyより小さい要素の個数を求めることができる．
        // この場合，bより小さい要素の数である．
        ll pre = lower_bound(A.begin(), A.end(), b) - A.begin();
        // 末尾のイテレータからupper_boundのイテレータを引くと，あるkeyより大きい要素の個数を求めることができる．
        // この場合，bより大きい要素の数である．
        ll over = C.end() - upper_bound(C.begin(), C.end(), b);
        res += pre * over;
    }
    cout << res << endl;
    return 0;
}