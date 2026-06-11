#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int cnt = 0;
    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int c = 0; c <= C; c++) {
                if (500 * a + 100 * b + 50 * c == X) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}

int main() {
    solve();

    return 0;
}
