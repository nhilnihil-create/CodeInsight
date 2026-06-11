#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int>ans;

ll N, A, B;
void ind(){
    for (int i = 0; i < A; ++i) {
        ans.push_back(N - A + 1 + i);
    }
    N -= A; B--;
}

void solve(){
    for (int i = B; i <= N; ++i) {
        ans.push_back(i);
    }
    for (int i = B - 1; i > 0; --i) {
        ans.push_back(i);
    }
}

int main() {
    cin >> N >> A >> B;
    ans.reserve(N);

    if (N + 1 < A + B || N > A * B) {
        cout << -1 << "\n";
        return 0;
    }

    int flag = 0;
    if (A < B) {
        flag = 1;
        ll temp = A;
        A = B;
        B = temp;
    }

    if (N < A * 2) {
        ind();
    } else {
        while (N > A * 2) {
            ind();
        }

        for (int i = A + 1; i <= N; ++i) {
            ans.push_back(i);
        }
        N = A;
        B--;
    }

    if (B) solve();
    if (flag) reverse(ans.begin(), ans.end());
    for (int x: ans) cout << x << " ";
    cout << "\n";
    return 0;
}