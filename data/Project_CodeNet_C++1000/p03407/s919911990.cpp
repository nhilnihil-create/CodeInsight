#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

int A, B, C;
int main() {
    cin >> A >> B >> C;
    string ans = "No";
    if (A + B >= C) {
        ans = "Yes";
    }

    cout << ans << endl;
}