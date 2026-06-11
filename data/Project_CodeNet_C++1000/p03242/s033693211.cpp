#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string s = to_string(n);
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == '1') cout << '9';
        else cout << '1';
    }


}







