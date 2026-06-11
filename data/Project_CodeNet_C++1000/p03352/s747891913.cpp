#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int main() {

    int x;
    cin >> x;
    int res = 1;
    for (int i = 2; i <= x; ++i) {
        int power = i * i;
        for (int j = 2; ; ++j) {
            if (power > x) break;
            res = max(res, power);
            power *= i;
        }
    }
    cout << res << endl;
    return 0;
}