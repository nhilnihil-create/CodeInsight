#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    int *a = new int[4];
    a[3] = n / 1000;
    a[2] = (n - a[3] * 1000) / 100;
    a[1] = (n - a[3] * 1000 - a[2] * 100) / 10;
    a[0] = (n - a[3] * 1000 - a[2] * 100 - a[1] * 10);

    for (int mask = 0; mask < (1 << 3); mask++) {
        int sum = a[3];
        for (int i = 2; i >= 0; i--) {
            if (1 & mask >> i) {
                sum += a[i];
            } else {
                sum += -a[i];
            }
        }
        if (sum == 7) {
            string result = "";
            for (int i = 0; i < 3; i++) {
                result += to_string(a[i]) + (((mask >> i) & 1) ? "+" : "-");
            }
            result += to_string(a[3]);
            reverse(result.begin(), result.end());
            cout << result << "=7" << endl;
            return 0;
        }
    }

    
    return 0;
}