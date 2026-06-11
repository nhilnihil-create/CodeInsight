#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    int sum = 0;
    rep(i, N) {
        cin >> vec[i];
        sum += vec[i];
    }
    int ans = N;
    int mini = 1e5;
    rep(i, N) {
        if (abs(sum - N*vec[i]) < mini) {
            mini = abs(sum - N*vec[i]);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}