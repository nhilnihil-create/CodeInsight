#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    rep(i, N + 2) {
        if (1LL * i * i > N) {
            cout << (i - 1) * (i - 1) << "\n";
            return 0;
        }
    }
}