#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int n, m; cin >> n >> m;

    if ((Int)n*m == 1) puts("1");
    else if ((Int)n*m == 2) puts("0");
    else if ((Int)n*m == 3) ("1");
    else {
        if (n == 1 || m == 1) {
            cout << (Int)n*m - 2 << endl;
        }
        else cout << (Int)(n-2)*(m-2) << endl;
    }
}
