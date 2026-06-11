#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long A, long long B, long long C) {
    auto money = B;
    auto ans = 0;
    loop (i, 1, 10000) {
        if (A <= money) {
            money -= A;
            ans++;
            if (ans == C) {
                break;
            }
        } else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    solve(A, B, C);
    return 0;
}
