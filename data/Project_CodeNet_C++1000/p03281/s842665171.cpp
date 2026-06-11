#include <iostream>
#include <string>
#include <vector>

#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int div(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cnt++;
    }
    return cnt;
}

int main() {
    fastio;
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            int cnt_ = div(i);
            if (cnt_ == 8)
                cnt++;
        }
    }
    cout << cnt << endl;
}

