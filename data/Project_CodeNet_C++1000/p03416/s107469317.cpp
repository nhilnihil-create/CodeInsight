#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = 0;
    for (int i = A; i <= B; i++) {
        string s = to_string(i);
        int n = s.size();
        for (int j = 0; j < (n + 1) / 2; j++) {
            if (s[j] != s[n - 1 - j]) break;
            if (j == (n + 1) / 2 - 1) ans++;
        }
    }
    cout << ans << endl;
}