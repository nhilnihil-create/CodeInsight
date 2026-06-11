#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B;
    rep(i, N) { cin >> A[i]; }

    bool judge = 1;
    rep(j, N) {
        int cur = -1;
        rep(i, A.size()) {
            if (A[i] == i + 1)
                cur = i;
        }

        if (cur == -1) {
            judge = 0;
            break;
        } else {
            B.push_back(A[cur]);
            A.erase(A.begin() + cur);
        }
    }

    if (judge) {
        reverse(B.begin(), B.end());
        for (auto b : B)
            cout << b << endl;
    } else
        cout << -1 << endl;
}