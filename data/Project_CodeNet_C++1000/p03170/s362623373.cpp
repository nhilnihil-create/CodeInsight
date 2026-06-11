#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector<int> A;
int n, k;
int dp1[MAX];
int dp2[MAX];
void solve1() {
    for (int i = 0; i < MAX; i++) dp1[i] = 0;
    for (int i = 0; i < MAX; i++) {
        for (auto a: A) {
            if (i + a >= MAX) break;
            // if (dp1[i+a] == -1) dp1[i+a] = 1 - dp1[i];
            if (dp1[i] == 0) dp1[i+a] = 1;
        }
    }
    string ans;
    if (dp1[k] == 1) ans = "First";
    else ans = "Second";
    cout << ans << endl;
    return;
}
// void solve2() {
//     for (int i = 0; i < MAX; i++) dp2[i] = 0;
//     for (int i = 0; i < MAX; i++) {
//         for (auto a: A) {
//             if (i - a >= 0 && dp2[i-a] == 0) dp2[i] = 1;
//         }
//     }
//     string ans;
//     if (dp2[k] == 1) ans = "First";
//     else ans = "Second";
//     cout << "ans2: " << ans << endl;
//     return;
// }

int main() {
    cin >> n >> k;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    solve1();
    // solve2();
    return 0;
}