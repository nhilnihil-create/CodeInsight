#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int>L, R;

ll solve(int k) {
    auto cmpL = [&](int a, int b){ return L[a] < L[b]; };
    auto cmpR = [&](int a, int b){ return R[a] > R[b]; };
    priority_queue< int, vector<int>, decltype(cmpL) > que_left {cmpL};
    priority_queue< int, vector<int>, decltype(cmpR) > que_right (cmpR);
    for (int i = 0; i < N; ++i) {
        que_left.push(i); que_right.push(i);
    }

    ll ans = 0;
    vector<int>flag(N, 0);
    int cur = 0;
    for (int i = 0; i < N; ++i) {
        if ((i + k) % 2) {
            while (flag[que_right.top()]) que_right.pop();
            int t = que_right.top();
            if (R[t] >= cur) break;
            ans += cur - R[t];
            cur = R[t];
            flag[t] = 1;
        } else {
            while (flag[que_left.top()]) que_left.pop();
            int t = que_left.top();
            if (L[t] <= cur) break;
            ans += L[t] - cur;
            cur = L[t];
            flag[t] = 1;
        }
    }

    ans += abs(cur);
    return ans;
}

int main() {
    cin >> N;
    L.resize(N); R.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >>  R[i];
    }

    ll ans = max(solve(0), solve(1));
    cout << ans << "\n";
    return 0;
}