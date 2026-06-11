#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 305;
// const int MAX = 4;
/* global variables */
/* funciton */
/* main */
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    // dp[i] : i個, true - win, false - lose
    vector<bool> dp(K+1, false);
    dp[0] = false;
    for (int i = 0; i < K; i++) {
        for (int x : a) {
            int ne = i + x;
            if (ne > K) continue;
            if (dp[i] == false) dp[ne] = true;
        }
    }
    if (dp[K]) cout << "First" << '\n';
    else cout << "Second" << '\n';
}