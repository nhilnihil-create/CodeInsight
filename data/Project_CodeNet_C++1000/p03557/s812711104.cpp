// 6/4
// 3-1-1. lower_bound 類題
// ARC084-Aと同じ問題
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

// ai >= kとなる最小のiを返す
int lower_bound(vector<int> &A, int v) {
    int n = A.size();
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int mid = (right + left) / 2;

        if (A[mid] >= v) right = mid;
        else left = mid;
    }
    return right;
}

// ai <= kとなる最大のiを返す
int upper_bound(vector<int> &A, int v) {
    int n = A.size();
    int left = -1;  // 左側が常に条件を満たす。最終的に解となる。
    int right = n;  // 右側は常にai>kとなる。
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (A[mid] <= v) left = mid;
        else right = mid;
    }
    return left;
}

int main() {
    ll N;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;

    // rep(i, N) {
    //     int minj = lower_bound(B, A[i] + 1);
    //     // printf("A[%d]+1, minj = %d, %d\n", i, A[i] + 1, minj);
    //     for (int j = minj; j < N; j++) {
    //         int mink = lower_bound(C, B[j] + 1);
    //         ans += N - mink;
    //     }
    // }

    rep(i, N) {
        ll maxa = upper_bound(A, B[i] - 1);
        ll minc = lower_bound(C, B[i] + 1);
        ans += (maxa + 1) * (N - minc);
    }

    cout << ans << endl;
}