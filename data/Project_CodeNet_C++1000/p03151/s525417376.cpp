#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    vector<int> vec(N);
    rep(i, N) vec[i] = A[i] - B[i];
    sort(rALL(vec));
    if(vec[N - 1] >= 0) {
        cout << 0 << endl;
        return 0;
    }
    int left = 0, right = N - 1;
    int ans = 0;
    while (vec[left] > 0 && vec[right] < 0) {
        int diff = max(0, vec[left] + vec[right]);
        vec[right] = vec[left] - diff + vec[right];
        vec[left] = diff;
        if (vec[left] <= 0) {
            left += 1;
            ans += 1;
        }
        if (vec[right] >= 0) {
            right -= 1;
            ans += 1;
        }
    }
    rep(i, N) if (vec[i] < 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans + 1 << endl;
    return 0;
}