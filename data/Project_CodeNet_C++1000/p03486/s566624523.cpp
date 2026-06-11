#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    sort(S.begin(), S.end());
    sort(T.rbegin(), T.rend());
    cout << (S < T ? "Yes" : "No") << '\n';
    return 0;
}
