#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string ans;
    for(int i = 0; i < 3; i++) {
        string S;
        cin >> S;
        ans += S[i];
    }
    cout << ans;
    return 0;
}