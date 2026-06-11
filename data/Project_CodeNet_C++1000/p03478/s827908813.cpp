#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0, a = 0, b = 0, temp = 0, tempans = 0, ans = 0;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; ++i) {
        temp = i;
        tempans = 0;
        if (temp <= 9 && temp >= a && temp <= b) {
            ans += temp;
        }

        while (temp >= 10) {
            tempans += temp % 10;
            temp /= 10;
            if (temp / 10 <= 0) {
                tempans += temp;
                if (tempans >= a && tempans <= b) {
                    ans += i;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}