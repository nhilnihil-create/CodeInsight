#include <bits/stdc++.h>
using namespace std;

long ans;
string S;

int main(void) {

    cin >> S;

    for (long i = 0; i < S.length(); i++) {
        for (long j = 1; j <= S.length() - i; j++) {
            string s = S.substr(i, j);
            bool f = true;
            for (auto e: s) {
                if (e != 'A' && e != 'T' && e != 'C' && e != 'G') {
                    f = false;
                    break;
                }
            }

            if (f) {
                ans = max(ans, j);
            }
        }
    }

    cout << ans << endl;

    return 0;

}