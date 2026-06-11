#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int X;
    cin >> X;
    int maxValue = 1;
    for (int i = 2; i <= X; i++) {  // O(N^2) -> 1000 * 1000 = 10^6
        int tmp = i * i;
        while(tmp <= X) {
            maxValue = max(maxValue, tmp);
            tmp *= i;
        }
    }

    cout << maxValue << endl;

    return 0;
}
