#include <iostream>
#include <bitset>

using namespace std;

int main() {
    int n;
    cin >> n;

    bitset<4000010> dp;
    dp[0] = true;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dp |= dp << a;
        sum += a;
    }

    int ret = (sum + 1) / 2;
    while (true) {
        if (dp[ret]) {
            cout << ret << endl;
            break;
        }
        ret++;
    }
    return 0;
}