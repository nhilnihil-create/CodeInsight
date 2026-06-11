#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;


    int i = 0;
    while (S[i] == '.') { ++i; }

    int j = N - 1;
    while (S[j] == '#') { --j; }

    int n = j - i + 1;
    string T = S.substr(i, n);
    vector<int> X(n), Sum(n + 1);
    S[0] = 0;
    for (int i = 0; i < n; ++i) {
        X[i] = T[i] == '#' ? 1 : 0;
        Sum[i + 1] = Sum[i] + X[i];
    }

    int ans = 200005;
    for(int i = 0; i <= n; ++i)
    {
        int left = Sum[i]; // 黒石=>白石
        int right = (n - i) - (Sum[n] - Sum[i]); // 白石=>黒石
        ans = min(ans, left + right);
    }
    cout << ans << endl;
}