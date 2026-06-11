#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    string S, ans = "AC\n";
    cin >> S;
    if (S[0] != 'A') ans = "WA\n";
    if (S[1] < 'a' || S[1] > 'z') ans = "WA\n";
    int C = 0, n = S.size();
    if (S[n - 1] < 'a' || S[n - 1] > 'z') ans = "WA\n";
    for (int i = 2; i < n - 1; i++) {
        if (S[i] == 'C') C++;
        else if (S[i] < 'a' || S[i] > 'z') ans = "WA\n";
    }
    if (C != 1) ans = "WA\n";
    cout << ans;
}