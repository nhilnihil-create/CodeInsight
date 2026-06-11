#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        char A = a[i], B = b[i], C = c[i];
        if(A != B && B != C && C != A) {
            ans += 2;
        }
        else if(A == B && B != C) {
            ans++;
        }
        else if(A == C && C != B) {
            ans++;
        }
        else if(B == C && A != B) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}