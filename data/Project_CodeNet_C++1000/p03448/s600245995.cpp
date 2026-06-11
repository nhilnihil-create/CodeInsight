#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int cnt = 0;

    for (int a = 0; a <= A; ++a) {
        for (int b = 0; b <= B; ++b) {
            for (int c = 0; c <= C; ++c) {
                if (500*a + 100*b + 50*c == X) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}