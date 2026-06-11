#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int numOfCanDivide(int x) {
    int count = 0;
    while (x % 100 == 0) {
        x /= 100;
        count++;
    }
    return count;
}

int main() {
    int D, N;
    cin >> D >> N;

    int MAX_VAL = 1010000;

    int count = 1;
    int ans = 0;
    for (int i = 1; i <= MAX_VAL; i++) {
        if(numOfCanDivide(i) == D) {
            if (count == N) ans = i;
            count++;
        }
    }

    cout << ans << endl;

    return 0;
}
