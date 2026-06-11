#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    string str = to_string(N);
    long ans = 0;
    for (int i = str.length() - 1; i > 0; i--) {
        if (str[i] != '9') {
            for (int j = 1; j <= i; j++) {
                if (str[i - j] != '0') {
                    str[i - j] -= 1;
                    break;
                } else {
                    str[i - j] = '9';
                }
            }
        }
        ans += 9;
    }
    ans += str[0] - '0';
    cout << ans << endl;

    return 0;
}