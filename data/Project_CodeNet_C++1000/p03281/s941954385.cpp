#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;

    int numOfdivisor = 0;
    for (int i = 1; i <= N; i = i + 2) {
        int count = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                count++;
                if (j * j != i) count++;
            }
        }
        if (count == 8) numOfdivisor++;
    }

    cout << numOfdivisor << endl;

    return 0;
}
